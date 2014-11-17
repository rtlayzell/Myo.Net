#pragma once

using namespace System;

#include "MyoEventArgs.hpp"
#include "Quaternion.hpp"


namespace Thalmic
{
	namespace Myo
	{
		public ref class RssiDataEventArgs : public MyoEventArgs
		{
		private:
			Byte _rssi;

		public:
			RssiDataEventArgs(IMyo^ myo, DateTimeOffset timestamp, Byte rssi)
				: MyoEventArgs(myo, timestamp), _rssi(rssi) { }

			property Byte Rssi
			{ Byte get( ) { return _rssi; } }
		};

	}
}
