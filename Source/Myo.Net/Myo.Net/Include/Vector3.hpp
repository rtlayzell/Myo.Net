#pragma once

namespace Thalmic
{
	namespace Myo
	{
		[System::Diagnostics::DebuggerDisplayAttribute("\\{X={X}, Y={Y}, Z={Z}\\}")]
		[System::Runtime::InteropServices::StructLayoutAttribute(System::Runtime::InteropServices::LayoutKind::Explicit)]
		public value class Vector3 sealed
		{
		public:
			static initonly Vector3 Zero = Vector3(0, 0, 0);

			[System::Runtime::InteropServices::FieldOffsetAttribute(0) ] double X; 
			[System::Runtime::InteropServices::FieldOffsetAttribute(8) ] double Y;
			[System::Runtime::InteropServices::FieldOffsetAttribute(16)] double Z;

			Vector3(double x, double y, double z);

			property double default[int] {
				double get(int index) { return *(&X + index); }
				void set(int index, double value) { *(&X + index) = value; }
			}

			property double Length { double get( ) { return System::Math::Sqrt(this->LengthSqr); } }
			property double LengthSqr { double get( ) { return this->Dot(*this); } }

			static Vector3 operator + (Vector3 lhs, Vector3 rhs);
			static Vector3 operator - (Vector3 lhs, Vector3 rhs);
			static Vector3 operator * (Vector3 lhs, double value);
			static Vector3 operator * (double value, Vector3 rhs);
			static Vector3 operator / (Vector3 lhs, double value);

			
			void Normalize( );

			double Dot(Vector3 rhs);
			Vector3 Cross(Vector3 rhs);
			double AngleTo(Vector3 rhs);
		};
	}
}
