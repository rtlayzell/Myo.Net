#include "stdafx.h"
#include "Quaternion.hpp"


namespace Thalmic
{
	namespace Myo
	{
		Quaternion::Quaternion(double x, double y, double z, double w)
			: X(x), Y(y), Z(z), W(w) { }

		Quaternion Quaternion::operator * (Quaternion lhs, Quaternion rhs)
		{
			return Quaternion( 
				lhs.W * rhs.X + lhs.X * rhs.W + lhs.Y * rhs.Z - lhs.Z * rhs.Y,
				lhs.W * rhs.Y - lhs.X * rhs.Z + lhs.Y * rhs.W + lhs.Z * rhs.X, 
				lhs.W * rhs.Z + lhs.X * rhs.Y - lhs.Y * rhs.X + lhs.Z * rhs.W,
				lhs.W * rhs.W - lhs.X * rhs.X - lhs.Y * rhs.Y - lhs.Z * rhs.Z);
		}

		/*Quaternion Quaternion::Inverse( )
		{
		}*/

		Quaternion Quaternion::Conjugate( )
		{
			return Quaternion(-X, -Y, -Z, W);
		}

		Quaternion Quaternion::Normalized( )
		{
			double length = this->Length;
			return Quaternion(X / length, Y / length, Z / length, W / length);
		};
	}
}
