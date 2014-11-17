#include "stdafx.h"
#include "Vector3.hpp"
#include "myo/myo.hpp"

namespace Thalmic
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

		void Vector3::Normalize( )
		{
			*this /= this->Length;
		}

		double Vector3::Dot(Vector3 rhs)
		{
			return X * rhs.X
				+ Y * rhs.Y
				+ Z * rhs.Z;
		}

		Vector3 Vector3::Cross(Vector3 rhs)
		{
			return Vector3(
				Y * rhs.Z - Z * rhs.Y,
				Z * rhs.X - X * rhs.Z,
				X * rhs.Y - Y * rhs.X);
		}

		double Vector3::AngleTo(Vector3 rhs)
		{
			return System::Math::Acos(Dot(rhs) / (Length * rhs.Length));
		}
	}
}