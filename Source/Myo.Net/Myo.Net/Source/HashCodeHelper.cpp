#include "stdafx.h"
#include "HashCodeHelper.hpp"

namespace MyoNet
{
	namespace Myo
	{
		int HashCodeHelper::CombineHashCodes(int lhs, int rhs)
		{
			return (((lhs << 5) + lhs) ^ rhs);
		}
	}
}

