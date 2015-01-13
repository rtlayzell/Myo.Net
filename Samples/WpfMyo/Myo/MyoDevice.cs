using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using MyoNet.Myo;

namespace WpfMyo.Myo
{

	public static class MyoDevice
	{
		private static IHub _hub;
		private static IList<IMyo> _myos;
		private static IDictionary<RoutedEvent, IList<UIElement>> _elements;

		public static readonly RoutedEvent ConnectedEvent =
			EventManager.RegisterRoutedEvent("Paired", RoutingStrategy.Bubble,
			typeof(MyoRoutedEventHandler), typeof(MyoDevice));

		public static readonly RoutedEvent DisconnectedEvent =
			EventManager.RegisterRoutedEvent("Disconnected", RoutingStrategy.Bubble,
			typeof(MyoRoutedEventHandler), typeof(MyoDevice));

		public static readonly RoutedEvent AccelerationChangedEvent =
			EventManager.RegisterRoutedEvent("tAccelerationChanged", RoutingStrategy.Bubble,
			typeof(AccelerationEventHandler), typeof(MyoDevice));

		public static readonly RoutedEvent OrientationChangedEvent =
			EventManager.RegisterRoutedEvent("OrientationChanged", RoutingStrategy.Bubble,
			typeof(MyoRoutedEventHandler), typeof(MyoDevice));

		public static void AddConnectedHandler(DependencyObject d, MyoRoutedEventHandler handler)
		{
			AddHandler(MyoDevice.ConnectedEvent, d, handler);
		}

		public static void RemoveConnectedHandler(DependencyObject d, MyoRoutedEventHandler handler)
		{
			RemoveHandler(MyoDevice.ConnectedEvent, d, handler);
		}

		public static void AddDisconnectedHandler(DependencyObject d, MyoRoutedEventHandler handler)
		{
			AddHandler(MyoDevice.DisconnectedEvent, d, handler);
		}

		public static void RemoveDisconnectedHandler(DependencyObject d, MyoRoutedEventHandler handler)
		{
			RemoveHandler(MyoDevice.DisconnectedEvent, d, handler);
		}

		public static void AddAccelerationChangedHandler(DependencyObject d, AccelerationEventHandler handler)
		{
			AddHandler(MyoDevice.AccelerationChangedEvent, d, handler);
		}

		public static void RemoveAccelerationChangedHandler(DependencyObject d, AccelerationEventHandler handler)
		{
			RemoveHandler(MyoDevice.AccelerationChangedEvent, d, handler);
		}

		public static void AddOrientationChangedHandler(DependencyObject d, MyoRoutedEventHandler handler)
		{
			AddHandler(MyoDevice.OrientationChangedEvent, d, handler);
		}

		public static void RemoveOrientationChangedHandler(DependencyObject d, MyoRoutedEventHandler handler)
		{
			RemoveHandler(MyoDevice.OrientationChangedEvent, d, handler);
		}

		static MyoDevice( )
		{
			_hub = new Hub("com.wpf-example.demo");
			_hub.MyoConnected += OnMyoConnected;
			_hub.MyoDisconnected += OnMyoDisconnected;
			//_hub.MyoPaired += OnMyoPaired;
			//_hub.MyoPaired += OnMyoUnpaired;

			_myos = new List<IMyo>( );

			_elements = new Dictionary<RoutedEvent, IList<UIElement>>( );
			_elements.Add(MyoDevice.ConnectedEvent, new List<UIElement>( ));
			_elements.Add(MyoDevice.DisconnectedEvent, new List<UIElement>( ));
			_elements.Add(MyoDevice.AccelerationChangedEvent, new List<UIElement>( ));

			// invoke Hub.Run( ) in a background thread for the duration of the program.
			Thread t = new Thread(( ) => _hub.Run( ));
			t.IsBackground = true;
			t.Start( );
		}
		
		static void OnMyoConnected(object sender, MyoEventArgs e)
		{
			_myos.Add(e.Myo);
			e.Myo.AccelerometerDataAcquired += OnAccelerationDataAcquired;
			e.Myo.OrientationDataAcquired += OnOrientationDataAcquired;

			var args = new MyoRoutedEventArgs(MyoDevice.ConnectedEvent, sender, e.Myo, e.TimeStamp);
			RaiseEvent(MyoDevice.ConnectedEvent, args);
		}

		static void OnMyoDisconnected(object sender, MyoEventArgs e)
		{
			_myos.Remove(e.Myo);
			e.Myo.AccelerometerDataAcquired -= OnAccelerationDataAcquired;
			e.Myo.OrientationDataAcquired -= OnOrientationDataAcquired;

			var args = new MyoRoutedEventArgs(MyoDevice.DisconnectedEvent, sender, e.Myo, e.TimeStamp);
			RaiseEvent(MyoDevice.DisconnectedEvent, args);
		}

		static void OnAccelerationDataAcquired(object sender, AccelerometerDataEventArgs e)
		{
			var args = new AccelerationChangedEventArgs(MyoDevice.AccelerationChangedEvent, sender, e.Myo, e.TimeStamp, e.Accelerometer);
			RaiseEvent(MyoDevice.AccelerationChangedEvent, args);
		}

		static void OnOrientationDataAcquired(object sender, OrientationDataEventArgs e)
		{
			//var args = new AccelerationChangedEventArgs(MyoDevice.AccelerationChangedEvent, sender, e.Myo, e.TimeStamp, e.Accelerometer);
			//RaiseEvent(MyoDevice.AccelerationChangedEvent, args);
		}

		private static void AddHandler(RoutedEvent ev, DependencyObject d, Delegate handler)
		{
			UIElement e = d as UIElement;
			if (e != null) e.AddHandler(ev, handler);

			if (!_elements[ev].Contains(e))
				_elements[ev].Add(e);
		}

		private static void RemoveHandler(RoutedEvent ev, DependencyObject d, Delegate handler)
		{
			UIElement e = d as UIElement;
			if (e != null) e.RemoveHandler(ev, handler);

			if (!_elements[ev].Contains(e))
				_elements[ev].Remove(e);
		}

		static void RaiseEvent(RoutedEvent ev, MyoRoutedEventArgs args)
		{
			if (Application.Current == null) return;

			Application.Current.Dispatcher.Invoke(new Action(( ) =>
			{
				foreach (var elem in _elements[ev])
					elem.RaiseEvent(args);
			}));
		}
	}
}
