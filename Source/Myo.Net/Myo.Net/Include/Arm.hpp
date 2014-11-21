
#pragma once

#include "myo/cxx/Pose.hpp"

namespace MyoNet
{
	namespace Myo
	{
		/// <summary>
		/// Enumeration identifying a right arm or left arm.
		/// </summary>
		public enum class Arm
		{
			Left = libmyo_arm_left,
			Right = libmyo_arm_right,
			Unknown = libmyo_arm_unknown,
		};

		/// <summary>
		/// Possible directions for Myo's +x axis relative to a user's arm.
		/// </summary>
		public enum class XDirection
		{
			TowardWrist = libmyo_x_direction_toward_wrist,
			TowardElbow = libmyo_x_direction_toward_elbow,
			Unknown = libmyo_x_direction_unknown,
		};
	}
}