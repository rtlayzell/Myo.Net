#pragma once

using namespace System;

#include "MyoEventArgs.hpp"
#include "Arm.hpp"

namespace MyoNet
{
	namespace Myo
	{
		public ref class RecognizedArmEventArgs : public MyoEventArgs
		{
		private:
			initonly Arm _arm;
			initonly XDirection _xDirection;

		public:
			RecognizedArmEventArgs(IMyo^ myo, DateTimeOffset timestamp, Arm arm, XDirection xDirection)
				: MyoEventArgs(myo, timestamp), _arm(arm), _xDirection(xDirection) { }

			property MyoNet::Myo::Arm Arm { MyoNet::Myo::Arm get( ) { return _arm; } }
			property MyoNet::Myo::XDirection XDirection { MyoNet::Myo::XDirection get( ) { return _xDirection; } }
		};
	}
}
