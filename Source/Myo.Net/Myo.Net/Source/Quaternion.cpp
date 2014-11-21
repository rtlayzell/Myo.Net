#include "stdafx.h"
#include "Quaternion.hpp"
#include "HashCodeHelper.hpp"

namespace MyoNet
{
	namespace Myo
	{
		Quaternion::Quaternion(double x, double y, double z, double w)
			: _x(x), _y(y), _z(z), _w(w) { }

		bool Quaternion::operator == (Quaternion lhs, Quaternion rhs)
		{
			return lhs.Equals(rhs);
		}

		bool Quaternion::operator != (Quaternion lhs, Quaternion rhs)
		{
			return !lhs.Equals(rhs);
		}

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

		int Quaternion::GetHashCode( )
		{
			int hash = this->X.GetHashCode( );
			hash = HashCodeHelper::CombineHashCodes(hash, this->Y.GetHashCode( ));
			hash = HashCodeHelper::CombineHashCodes(hash, this->Z.GetHashCode( ));
			hash = HashCodeHelper::CombineHashCodes(hash, this->W.GetHashCode( ));

			return hash;
		}

		bool Quaternion::Equals(Object^ obj)
		{
			if (dynamic_cast<Quaternion^>(obj) == nullptr)
				return false;
			return Equals(static_cast<Quaternion>(obj));
		}

		bool Quaternion::Equals(Quaternion other)
		{
			return this->X.Equals(other.X)
				&& this->Y.Equals(other.Y)
				&& this->Z.Equals(other.Z)
				&& this->Z.Equals(other.W);
		}

		String^ Quaternion::ToString( )
		{
			return ToString("G", CultureInfo::CurrentCulture);
		}

		String^ Quaternion::ToString(String^ format)
		{
			return ToString(format, CultureInfo::CurrentCulture);
		}

		String^ Quaternion::ToString(String^ format, IFormatProvider^ formatProvider)
		{
			StringBuilder^ sb = gcnew StringBuilder( );
			String^ sep = NumberFormatInfo::GetInstance(formatProvider)->NumberGroupSeparator + " ";

			sb->Append("{");
			sb->Append("X:" + ((IFormattable^)this->X)->ToString(format, formatProvider));
			sb->Append(sep);
			sb->Append("Y:" + ((IFormattable^)this->Y)->ToString(format, formatProvider));
			sb->Append(sep);
			sb->Append("Z:" + ((IFormattable^)this->Z)->ToString(format, formatProvider));
			sb->Append(sep);
			sb->Append("W:" + ((IFormattable^)this->W)->ToString(format, formatProvider));
			sb->Append("}");

			return sb->ToString( );
		}
	}
}
