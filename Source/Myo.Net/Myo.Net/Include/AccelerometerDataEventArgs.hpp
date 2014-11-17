#pragma once

using namespace System;

#include "MyoEventArgs.hpp"
#include "Vector3.hpp"


namespace Thalmic
{
	namespace Myo
	{
		public ref class AccelerometerDataEventArgs : public MyoEventArgs
		{
		private:
			initonly Vector3 _accelerometer;

		public:
			AccelerometerDataEventArgs(IMyo^ myo, DateTimeOffset timestamp, Vector3 accelerometer)
				: MyoEventArgs(myo, timestamp), _accelerometer(accelerometer) { }

			property Vector3 Accelerometer
			{ Vector3 get( ) { return _accelerometer; } }
		};
	}
}
