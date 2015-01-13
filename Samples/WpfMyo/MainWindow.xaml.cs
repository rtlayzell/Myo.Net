﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using MyoNet.Myo;
using WpfMyo.Myo;

namespace WpfMyo
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		private Queue<Vector3> accel = new Queue<Vector3>( );
		private Queue<Quaternion> orient = new Queue<Quaternion>( );

		public MainWindow( )
		{
			InitializeComponent( );
		}

		private void OnMyoConnected(object sender, MyoRoutedEventArgs e)
		{
			
		}

		private void OnMyoAccelerationChanged(object sender, AccelerationChangedEventArgs e)
		{
			// we use the average of the past 20 values of e.Acceleration
			// to smooth the values being visualized in the UI.

			if (accel.Count >= 20) accel.Dequeue( );
			accel.Enqueue(e.Acceleration);

			Vector3 sum = Vector3.Zero;
			foreach (var vec in accel)
				sum += vec;

			sum /= accel.Count;

			xbar.Value = sum.X * xbar.Maximum;
			ybar.Value = sum.Y * ybar.Maximum;
			zbar.Value = sum.Z * zbar.Maximum;
		}

		private void OnMyoOrientationChanged(object sender, OrientationChangedEventArgs e)
		{
			// we use the average of the past 20 values of e.Acceleration
			// to smooth the values being visualized in the UI.

			if (orient.Count >= 20) orient.Dequeue( );
			orient.Enqueue(e.Orientation);

			Quaternion sum = Quaternion.Zero;
			foreach (var vec in orient)
				sum += vec;

			sum.X /= orient.Count;
			sum.Y /= orient.Count;
			sum.Z /= orient.Count;
			sum.W /= orient.Count;

			xbar2.Value = Quaternion.Roll(sum) * xbar2.Maximum;
			ybar2.Value = Quaternion.Pitch(sum) * ybar2.Maximum;
			zbar2.Value = Quaternion.Yaw(sum) * zbar2.Maximum;
		}
	}
}
