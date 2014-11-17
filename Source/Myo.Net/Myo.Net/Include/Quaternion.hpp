#pragma once

using namespace System;

namespace Thalmic
{
	namespace Myo
	{
		[System::Diagnostics::DebuggerDisplayAttribute("\\{X={X}, Y={Y}, Z={Z}, W={W}\\}")]
		[System::Runtime::InteropServices::StructLayoutAttribute(System::Runtime::InteropServices::LayoutKind::Explicit)]
		public value struct Quaternion sealed
		{
		public:
			static initonly Quaternion Zero = Quaternion(0, 0, 0, 0);

			[System::Runtime::InteropServices::FieldOffsetAttribute(0) ] double X; 
			[System::Runtime::InteropServices::FieldOffsetAttribute(8) ] double Y; 
			[System::Runtime::InteropServices::FieldOffsetAttribute(16)] double Z; 
			[System::Runtime::InteropServices::FieldOffsetAttribute(24)] double W;

			Quaternion(double x, double y, double z, double w);

			property double default[int] {
				double get(int index) { return *(&X + index); }
				void set(int index, double value) { *(&X + index) = value; }
			}

			property double Length { 
				double get( ) {
					return Math::Sqrt(LengthSquared);
				}
			}

			property double LengthSquared { 
				double get( ) {
					return X * X + Y * Y + Z * Z + W * W;
				}
			}

			/*property double Roll { double get( ); }
			property double Pitch { double get( ); }
			property double Yaw { double get( ); }*/

			static Quaternion operator * (Quaternion lhs, Quaternion rhs);

			//Quaternion Inverse( );
			Quaternion Conjugate( );
			Quaternion Normalized( );
		};
	}
}