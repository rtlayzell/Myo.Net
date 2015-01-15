using System;
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
			xbar.Minimum = -xbar.Maximum;
			ybar.Minimum = -ybar.Maximum;
			zbar.Minimum = -zbar.Maximum;

			xbar2.Minimum = -xbar2.Maximum;
			ybar2.Minimum = -ybar2.Maximum;
			zbar2.Minimum = -zbar2.Maximum;
		}

		private void OnMyoConnected(object sender, MyoRoutedEventArgs e)
		{
			MessageBox.Show("hello world!");
		}

		private void OnMyoAccelerationChanged(object sender, AccelerationChangedEventArgs e)
		{
			// we use the average of the past 20 values of e.Acceleration
			// to smooth the values being visualized in the UI.

			if (accel.Count >= 10) accel.Dequeue( );
			accel.Enqueue(e.Acceleration);

			Vector3 avg = accel.Aggregate((x, y) => x + y) / accel.Count;

			xbar.Value = avg.X * xbar.Maximum;
			ybar.Value = avg.Y * ybar.Maximum;
			zbar.Value = avg.Z * zbar.Maximum;
		}

		private void OnMyoOrientationChanged(object sender, OrientationChangedEventArgs e)
		{
			// we use the average of the past 20 values of e.Acceleration
			// to smooth the values being visualized in the UI.

			if (orient.Count >= 10) orient.Dequeue( );
			orient.Enqueue(e.Orientation);

			Quaternion avg = orient.Aggregate((x, y) => x + y);

			avg.X /= orient.Count;
			avg.Y /= orient.Count;
			avg.Z /= orient.Count;
			avg.W /= orient.Count;

			xbar2.Value = Quaternion.Roll(avg) * xbar2.Maximum;
			ybar2.Value = Quaternion.Pitch(avg) * ybar2.Maximum;
			zbar2.Value = Quaternion.Yaw(avg) * zbar2.Maximum;
		}
	}
}
