#pragma once

using namespace System;

#include "MyoEventArgs.hpp"
#include "Vector3.hpp"


namespace MyoNet
{
	namespace Myo
	{
		public ref class GyroscopeDataEventArgs : public MyoEventArgs
		{
		private:
			initonly Vector3 _gyroscope;

		public:
			GyroscopeDataEventArgs(IMyo^ myo, DateTimeOffset timestamp, Vector3 gyroscope)
				: MyoEventArgs(myo, timestamp), _gyroscope(gyroscope) { }

			property Vector3 Gyroscope
			{ Vector3 get( ) { return _gyroscope; } }
		};
	}
}
