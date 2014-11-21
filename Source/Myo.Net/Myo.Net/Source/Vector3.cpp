#include "stdafx.h"
#include "Vector3.hpp"
#include "myo/myo.hpp"

namespace MyoNet
{
	namespace Myo
	{
		Vector3::Vector3(double x, double y, double z)
		{
			this->X = x;
			this->Y = y;
			this->Z = z;

		}

		Vector3 Vector3::operator + (Vector3 lhs, Vector3 rhs)
		{
			return Vector3(
				lhs.X + rhs.X,
				lhs.Y + rhs.Y,
				lhs.Z + rhs.Z);
		}

		Vector3 Vector3::operator - (Vector3 lhs, Vector3 rhs)
		{
			return Vector3(
				lhs.X - rhs.X,
				lhs.Y - rhs.Y,
				lhs.Z - rhs.Z);
		}

		Vector3 Vector3::operator * (Vector3 lhs, double value)
		{
			return Vector3(
				lhs.X * value,
				lhs.Y * value,
				lhs.Z * value);
		}

		Vector3 Vector3::operator * (double value, Vector3 rhs)
		{
			return Vector3(
				rhs.X * value,
				rhs.Y * value,
				rhs.Z * value);
		}

		Vector3 Vector3::operator / (Vector3 lhs, double value)
		{
			return Vector3(
				lhs.X / value,
				lhs.Y / value,
				lhs.Z / value);
		}

		Vector3 Vector3::Normalized( )
		{
			return *this / this->Length( );
		}

		double Vector3::DotProduct(Vector3 lhs, Vector3 rhs)
		{
			return 
				lhs.X * rhs.X + 
				lhs.Y * rhs.Y + 
				lhs.Z * rhs.Z;
		}

		Vector3 Vector3::CrossProduct(Vector3 lhs, Vector3 rhs)
		{
			return Vector3(
				lhs.Y * rhs.Z - lhs.Z * rhs.Y,
				lhs.Z * rhs.X - lhs.X * rhs.Z,
				lhs.X * rhs.Y - lhs.Y * rhs.X);
		}

		double Vector3::AngleTo(Vector3 lhs, Vector3 rhs)
		{
			return System::Math::Acos(DotProduct(lhs, rhs) / (lhs.Length( ) * rhs.Length( )));
		}
	}
}