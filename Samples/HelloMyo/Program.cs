﻿using System;
using MyoNet.Myo;

namespace HelloMyo
{
	class Program
	{
		private static int roll_w = 0;
		private static int pitch_w = 0;
		private static int yaw_w = 0;
		private static bool onArm = false;

		private static Pose currentPose;
		private static Arm whichArm;


		static void Main(string[] args)
		{
			try
			{
				using (var hub = new Hub("com.example.hello-myo"))
				{
					Console.WriteLine("Attempting to find a Myo...");
					IMyo myo = hub.WaitForMyo(TimeSpan.FromSeconds(10));
					if (myo == null)
						throw new TimeoutException("Unable to find a Myo!");

					Console.WriteLine("Connected to a Myo armband!\n");

					hub.MyoUnpaired += OnUnpair;

					myo.PoseChanged += OnPoseChanged;
					myo.OrientationDataAcquired += OnOrientationData;
					myo.RecognizedArm += OnRecognizedArm;
					myo.LostArm += OnLostArm;
					
					while (true)
					{
						hub.Run(TimeSpan.FromMilliseconds(1000 / 20));
						PrintDisplay( );
					}
				}
			}
			catch (Exception e)
			{
				Console.WriteLine("Error: {0}", e.Message);
				Console.WriteLine("Press any key to continue.");
				Console.ReadKey();
			}
		}

		private static void PrintDisplay()
		{
			// Clear the current line
			Console.Write('\r');

			Console.Write("[{0}]", new String('*', roll_w).PadRight(18));
			Console.Write("[{0}]", new String('*', pitch_w).PadRight(18));
			Console.Write("[{0}]", new String('*', yaw_w).PadRight(18));

			if (onArm)
			{
				Console.Write("[{0}][{1}]", 
					whichArm.ToString()[0], 
					currentPose.ToString().PadRight(13));
			}
			else
			{
				Console.Write("[?][".PadRight(17) + "]");
			}
		}

		// OnUnpair() is called whenever the Myo is disconnected from Myo Connect by the user.    
		static void OnUnpair(object sender, MyoEventArgs e)
		{
			// We've lost a Myo.
			// Let's clean up some leftover state.
			roll_w = 0;
			pitch_w = 0;
			yaw_w = 0;
			onArm = false;
		}

		static void OnOrientationData(object sender, OrientationDataEventArgs e)
		{
			// Calculate Euler angles (roll, pitch, and yaw) from the unit quaternion.        
			double roll = Quaternion.Roll(e.Orientation);
			double pitch = Quaternion.Pitch(e.Orientation);
			double yaw = Quaternion.Yaw(e.Orientation);

			// Convert the floating point angles in radians to a scale from 0 to 18.
			roll_w = (int)((roll + (double)Math.PI) / (Math.PI * 2.0) * 18);
			pitch_w = (int)((pitch + (double)Math.PI / 2.0) / Math.PI * 18);
			yaw_w = (int)((yaw + (double)Math.PI) / (Math.PI * 2.0) * 18);
		}

		// OnPose() is called whenever the Myo detects that the person wearing it has changed their pose, for example,
		// making a fist, or not making a fist anymore.
		static void OnPoseChanged(object sender, PoseChangedEventArgs e)
		{
			currentPose = e.Pose;

			// Vibrate the Myo whenever we've detected that the user has made a fist.
			if (e.Pose == Pose.Fist)
				e.Myo.Vibrate(VibrationType.Medium);
		}
		
		static void OnRecognizedArm(object sender, RecognizedArmEventArgs e)
		{
			onArm = true;
			whichArm = e.Arm;
		}

		static void OnLostArm(object sender, MyoEventArgs e)
		{
			onArm = false;
		}
	}
}
