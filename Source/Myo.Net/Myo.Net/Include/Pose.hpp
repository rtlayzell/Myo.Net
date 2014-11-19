
#pragma once

#include "myo/cxx/Pose.hpp"

namespace MyoNet
{
	namespace Myo
	{
		///<summary>
		/// Types of poses supported by the SDK. 
		///</summary>
		public enum class Pose
		{
			Rest = libmyo_pose_rest,
			Fist = libmyo_pose_fist,
			WaveIn = libmyo_pose_wave_in,
			WaveOut = libmyo_pose_wave_out,
			FingersSpread = libmyo_pose_fingers_spread,
			Reserved1 = libmyo_pose_reserved1,
			ThumbToPinky = libmyo_pose_thumb_to_pinky,
			Unknown = libmyo_pose_unknown,
		};
	}
}