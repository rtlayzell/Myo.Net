#pragma once

using namespace System;

#include "MyoEventArgs.hpp"

namespace MyoNet
{
	namespace Myo
	{
		public ref class EmgDataEventArgs : public MyoEventArgs
		{
		private:
			array<Byte>^ _emg;

		public:
			EmgDataEventArgs(IMyo^ myo, DateTimeOffset timestamp, array<Byte>^ emg)
				: MyoEventArgs(myo, timestamp), _emg(emg) { }

			property array<Byte>^ Sensors
			{ array<Byte>^ get( ) { return _emg; } }
		};
	}
}
