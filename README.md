# Myo.NET

Myo.NET is an unofficial wrapper of the [*Thalmic Labs Myo&trade;*](https://www.thalmic.com/en/myo/) [SDK](https://developer.thalmic.com/docs/api_reference/platform/index.html) for .NET managed languages.

## Support

- Myo SDK for Windows Beta version 7.0 (NuGet Package v2.0.0)
- Myo SDK for Windows Beta version 6.0 (NuGet Package v1.0.1)

## Dependencies

- [Myo Connect for Windows v0.6.0](https://developer.thalmic.com/downloads)
- [Myo Firmware v1.0.3](https://developer.thalmic.com/downloads)

## Installation

The recommended way to install Myo.NET is via the NuGet Package Manager.
Otherwise, add a reference to the Myo.Net.dll and copy the platform specific myo*.dll into the same directory as your application.

## Examples
- [Hello Myo](#hello-myo)

## Hello Myo

```C#
using System;
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
					hub.RecognizedArm += OnRecognizedArm;
					hub.LostArm += OnLostArm;

					myo.PoseChanged += OnPoseChanged;
					myo.OrientationDataAcquired += OnOrientationData;

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
			pitch_w = (int)((pitch + (float)Math.PI / 2.0) / Math.PI * 18);
			yaw_w = (int)((yaw + (float)Math.PI) / (Math.PI * 2.0) * 18);
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
```

## License

Myo.NET uses the [MIT License](LICENSE), Copyright &copy; 2014 Reegan Layzell
