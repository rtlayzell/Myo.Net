#pragma once

using namespace System;

#include "MyoEventArgs.hpp"
#include "Pose.hpp"


namespace MyoNet
{
	namespace Myo
	{
		public ref class PoseChangedEventArgs : public MyoEventArgs
		{
		private:
			MyoNet::Myo::Pose _pose;
		public:
			PoseChangedEventArgs(IMyo^ device, DateTimeOffset timestamp, MyoNet::Myo::Pose pose)
				: MyoEventArgs(device, timestamp), _pose(pose) { }

			property MyoNet::Myo::Pose Pose { MyoNet::Myo::Pose get( ){ return _pose; } }
		};
	}
}
