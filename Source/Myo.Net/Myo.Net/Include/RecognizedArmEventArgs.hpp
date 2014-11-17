#pragma once

using namespace System;

#include "MyoEventArgs.hpp"
#include "Arm.hpp"

namespace Thalmic
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

			property Thalmic::Myo::Arm Arm { Thalmic::Myo::Arm get( ) { return _arm; } }
			property Thalmic::Myo::XDirection XDirection { Thalmic::Myo::XDirection get( ) { return _xDirection; } }
		};
	}
}
