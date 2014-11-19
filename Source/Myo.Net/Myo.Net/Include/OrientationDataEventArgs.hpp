#pragma once

using namespace System;

#include "MyoEventArgs.hpp"
#include "Quaternion.hpp"


namespace MyoNet
{
	namespace Myo
	{
		public ref class OrientationDataEventArgs : public MyoEventArgs
		{
		private:
			Quaternion _orienation;
		public:
			OrientationDataEventArgs(IMyo^ device, DateTimeOffset timestamp, Quaternion orientation)
				: MyoEventArgs(device, timestamp), _orienation(orientation) { }

			property Quaternion Orientation { Quaternion get( ){ return _orienation; } }
		};
	}
}

