using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using MyoNet.Myo;

namespace WpfMyo.Myo
{
	public delegate void MyoRoutedEventHandler(object sender, MyoRoutedEventArgs e);
	public delegate void AccelerationEventHandler(object sender, AccelerationChangedEventArgs e);
	public delegate void OrientationEventHandler(object sender, OrientationChangedEventArgs e);

	public class MyoRoutedEventArgs : RoutedEventArgs
	{
		public IMyo Myo
		{
			get;
			internal set;
		}

		public DateTimeOffset TimeStamp
		{
			get;
			internal set;
		}

		public MyoRoutedEventArgs(RoutedEvent routedEvent, object source, IMyo myo, DateTimeOffset timeStamp) : base(routedEvent, source)
		{
			Myo = myo;
			TimeStamp = timeStamp;
		}
	}

	public class AccelerationChangedEventArgs : MyoRoutedEventArgs
	{
		public Vector3 Acceleration
		{ 
			get;
			private set;
		}

		public AccelerationChangedEventArgs(RoutedEvent routedEvent, object source, IMyo myo, DateTimeOffset timeStamp, Vector3 acceleration)
			: base(routedEvent, source, myo, timeStamp) 
		{
			Acceleration = acceleration;
		}
	}

	public class OrientationChangedEventArgs : MyoRoutedEventArgs
	{
		public Quaternion Orientation
		{
			get;
			private set;
		}

		public OrientationChangedEventArgs(RoutedEvent routedEvent, object source, IMyo myo, DateTimeOffset timeStamp, Quaternion orientation)
			: base(routedEvent, source, myo, timeStamp)
		{
			Orientation = orientation;
		}
	}
}
