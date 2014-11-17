#pragma once

using namespace System;

namespace Thalmic
{
	namespace Myo
	{
		///<summary>
		/// Structure that represents a rotation in three dimensions.
		///</summary>
		[System::Diagnostics::DebuggerDisplayAttribute("\\{X={X}, Y={Y}, Z={Z}, W={W}\\}")]
		[System::Runtime::InteropServices::StructLayoutAttribute(System::Runtime::InteropServices::LayoutKind::Explicit)]
		public value struct Quaternion sealed
		{
		private:
			[System::Runtime::InteropServices::FieldOffsetAttribute(0) ] double _x;
			[System::Runtime::InteropServices::FieldOffsetAttribute(8) ] double _y;
			[System::Runtime::InteropServices::FieldOffsetAttribute(16)] double _z;
			[System::Runtime::InteropServices::FieldOffsetAttribute(24)] double _w;

		public:
			///<summary>
			/// Represents a quaternion that has X, Y, Z and W values set to zero.
			///</summary>
			static initonly Quaternion Zero = Quaternion(0, 0, 0, 0);

			///<summary>
			/// Gets or sets the x component of the <see cref="Quaternion"/>.
			///</summary>
			property double X 
			{ 
				double get( ) { return _x; } 
				void set(double value) { _x = value; } 
			}
			
			///<summary>
			/// Gets or sets the y component of the <see cref="Quaternion"/>.
			///</summary>
			property double Y 
			{
				double get( ) { return _y; } 
				void set(double value) { _y = value; }
			}
			
			///<summary>
			/// Gets or sets the z component of the <see cref="Quaternion"/>.
			///</summary>
			property double Z 
			{ 
				double get( ) { return _z; } 
				void set(double value) { _z = value; } 
			}
			
			///<summary>
			/// Gets or sets the w component of the <see cref="Quaternion"/>.
			///</summary>
			property double W 
			{ 
				double get( ) { return _w; } 
				void set(double value) { _w = value; } 
			}

			///<summary>
			/// Initializes a new instance of the <see cref="Quaternion"/> with the specified components.
			///</summary>
			///<params>
			///<param name="x">The x component of the <see cref="Quaternion"/>.</param>
			///<param name="y">The y component of the <see cref="Quaternion"/>.</param>
			///<param name="z">The z component of the <see cref="Quaternion"/>.</param>
			///<param name="w">The w component of the <see cref="Quaternion"/>.</param>
			///</params>
			Quaternion(double x, double y, double z, double w);

			///<summary>
			/// Get or set a component in the <see cref="Quaternion"/> by index.
			///</summary>
			property double default[int] 
			{
				double get(int index) { return *(&_x + index); }
				void set(int index, double value) { *(&_x + index) = value; }
			}

			///<summary>
			/// Gets the length of the <see cref="Quaternion"/>
			///</summary>
			///<returns>The length of the <see cref="Quaternion"/>.</returns>
			double Length( ) { return Math::Sqrt(this->LengthSquared( )); }

			///<summary>
			/// Gets the length squared of the <see cref="Quaternion"/>
			///</summary>
			///<returns>The squared length of the <see cref="Quaternion"/>.</returns>
			double LengthSquared( ) { return X * X + Y * Y + Z * Z + W * W; }

			///<summary>
			/// Calculate the roll angle represented by the given unit <see cref="Quaternion"/>.
			///</summary>
			///<params>
			///<param name="quat">A unit <see cref="Quaternion"/>.</param>
			///</params>
			///<returns>The roll angle in radians.</returns>
			static double Roll(Quaternion quat);
			
			///<summary>
			/// Calculate the pitch angle represented by the given unit <see cref="Quaternion"/>.
			///</summary>
			///<params>
			///<param name="quat">A unit <see cref="Quaternion"/>.</param>
			///</params>
			///<returns>The pitch angle in radians.</returns>
			static double Pitch(Quaternion quat);
			
			///<summary>
			/// Calculate the yaw angle represented by the given unit <see cref="Quaternion"/>.
			///</summary>
			///<params>
			///<param name="quat">A unit <see cref="Quaternion"/>.</param>
			///</params>
			///<returns>The yaw angle in radians.</returns>
			static double Yaw(Quaternion quat);

			///<summary>
			/// Adds the specified <see cref="Quaternion"/>'s.
			///</summary>
			static Quaternion operator + (Quaternion lhs, Quaternion rhs);

			///<summary>
			/// Subtracts a <see cref="Quaternion"/> from another.
			///</summary>
			static Quaternion operator - (Quaternion lhs, Quaternion rhs);

			///<summary>
			/// Multiplies the specified <see cref="Quaternion"/>'s.
			///</summary>
			static Quaternion operator * (Quaternion lhs, Quaternion rhs);

			///<summary>
			/// Gets the inverse of the <see cref="Quaternion"/>.
			///</summary>
			Quaternion Inverse( );

			///<summary>
			/// Return a new unit <see cref="Quaternion"/> corresponding to the same rotation as this one.
			///</summary>
			Quaternion Normalized( );
		};
	}
}