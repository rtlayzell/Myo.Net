#include "stdafx.h"
#include "Quaternion.hpp"


namespace MyoNet
{
	namespace Myo
	{
		Quaternion::Quaternion(double x, double y, double z, double w)
			: _x(x), _y(y), _z(z), _w(w) { }


		Quaternion Quaternion::operator + (Quaternion lhs, Quaternion rhs)
		{
			return Quaternion(
				lhs.X + rhs.X,
				lhs.Y + rhs.Y,
				lhs.Z + rhs.Z,
				lhs.W + rhs.W);
		}

		Quaternion Quaternion::operator - (Quaternion lhs, Quaternion rhs)
		{
			return Quaternion(
				lhs.X - rhs.X,
				lhs.Y - rhs.Y,
				lhs.Z - rhs.Z,
				lhs.W - rhs.W);
		}

		Quaternion Quaternion::operator * (Quaternion lhs, Quaternion rhs)
		{
			return Quaternion( 
				lhs.W * rhs.X + lhs.X * rhs.W + lhs.Y * rhs.Z - lhs.Z * rhs.Y,
				lhs.W * rhs.Y - lhs.X * rhs.Z + lhs.Y * rhs.W + lhs.Z * rhs.X, 
				lhs.W * rhs.Z + lhs.X * rhs.Y - lhs.Y * rhs.X + lhs.Z * rhs.W,
				lhs.W * rhs.W - lhs.X * rhs.X - lhs.Y * rhs.Y - lhs.Z * rhs.Z);
		}

		Quaternion Quaternion::Inverse( )
		{
			return Quaternion(-X, -Y, -Z, W);
		}

		Quaternion Quaternion::Normalized( )
		{
			double length = this->Length( );
			return Quaternion(
				X / length, 
				Y / length, 
				Z / length, 
				W / length);
		};

		double Quaternion::Roll(Quaternion quat) 
		{ 
			return Math::Atan2(
				2.0 * (quat.W * quat.X + quat.Y * quat.Z), 
				1.0 - 2.0 * (quat.X * quat.X + quat.Y * quat.Y)); 
		}

		double Quaternion::Pitch(Quaternion quat) 
		{
			return Math::Asin(
				Math::Max(-1.0, Math::Min(1.0, 2.0 * (quat.W * quat.Y - quat.Z * quat.X)))); 
		}

		double Quaternion::Yaw(Quaternion quat)
		{ 
			return Math::Atan2(
				2.0 * (quat.W * quat.Z + quat.X * quat.Y),
				1.0 - 2.0 * (quat.Y * quat.Y + quat.Z * quat.Z)); 
		}
	}
}
