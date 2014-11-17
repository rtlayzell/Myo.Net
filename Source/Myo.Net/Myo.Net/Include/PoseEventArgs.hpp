#pragma once

using namespace System;

#include "MyoEventArgs.hpp"
#include "Pose.hpp"


namespace Thalmic
{
	namespace Myo
	{
		public ref class PoseEventArgs : public MyoEventArgs
		{
		private:
			Thalmic::Myo::Pose _pose;
		public:
			PoseEventArgs(IMyo^ device, DateTimeOffset timestamp, Thalmic::Myo::Pose pose)
				: MyoEventArgs(device, timestamp), _pose(pose) { }

			property Thalmic::Myo::Pose Pose { Thalmic::Myo::Pose get( ){ return _pose; } }
		};
	}
}
