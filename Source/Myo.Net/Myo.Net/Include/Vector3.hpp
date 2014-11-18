#pragma once

namespace Thalmic
{
	namespace Myo
	{
		///<summary>
		/// A vector of three components.
		///</summary>
		[System::Diagnostics::DebuggerDisplayAttribute("\\{X={X}, Y={Y}, Z={Z}\\}")]
		[System::Runtime::InteropServices::StructLayoutAttribute(System::Runtime::InteropServices::LayoutKind::Explicit)]
		public value class Vector3 sealed
		{
		private:
			[System::Runtime::InteropServices::FieldOffsetAttribute(0) ] double _x; 
			[System::Runtime::InteropServices::FieldOffsetAttribute(8) ] double _y;
			[System::Runtime::InteropServices::FieldOffsetAttribute(16)] double _z;

		public:
			///<summary>
			/// Represents a 3-dimension vector that has X, Y, and Z values set to zero.
			///</summary>
			static initonly Vector3 Zero = Vector3(0, 0, 0);

			///<summary>
			/// Initializes a new instance of the <see cref="Vector3"/> with the specified components.
			///</summary>
			///<params>
			///<param name="x">The x component of the <see cref="Vector3"/>.</param>
			///<param name="y">The y component of the <see cref="Vector3"/>.</param>
			///<param name="z">The z component of the <see cref="Vector3"/>.</param>
			///</params>
			Vector3(double x, double y, double z);

			///<summary>
			/// Gets or sets the x component of the <see cref="Vector3"/>.
			///</summary>
			property double X 
			{ 
				double get( ) { return _x; } 
				void set(double value) { _x = value; } 
			}
			
			///<summary>
			/// Gets or sets the y component of the <see cref="Vector3"/>.
			///</summary>
			property double Y 
			{
				double get( ) { return _y; } 
				void set(double value) { _y = value; }
			}
			
			///<summary>
			/// Gets or sets the z component of the <see cref="Vector3"/>.
			///</summary>
			property double Z 
			{ 
				double get( ) { return _z; } 
				void set(double value) { _z = value; } 
			}
			
			///<summary>
			/// Get or set a component in the <see cref="Vector3"/> by index.
			///</summary>
			property double default[int] 
			{
				double get(int index) { return *(&_x + index); }
				void set(int index, double value) { *(&_x + index) = value; }
			}

			///<summary>
			/// Gets the length of the <see cref="Vector3"/>
			///</summary>
			///<returns>The length of the <see cref="Vector3"/>.</returns>
			double Length( ) { return System::Math::Sqrt(this->LengthSquared( )); }

			///<summary>
			/// Gets the length squared of the <see cref="Vector3"/>
			///</summary>
			///<returns>The squared length of the <see cref="Vector3"/>.</returns>
			double LengthSquared( ) { return DotProduct(*this, *this); }

			///<summary>
			/// Adds the specified <see cref="Vector3"/>'s.
			///</summary>
			static Vector3 operator + (Vector3 lhs, Vector3 rhs);

			///<summary>
			/// Subtracts a <see cref="Vector3"/> from another.
			///</summary>
			static Vector3 operator - (Vector3 lhs, Vector3 rhs);

			///<summary>
			/// Multiplies the <see cref="Vector3"/> by specified scalar <paramref name="value"/>
			///</summary>
			static Vector3 operator * (Vector3 lhs, double value);
			
			///<summary>
			/// Multiplies the <see cref="Vector3"/> by specified scalar <paramref name="value"/>
			///</summary>
			static Vector3 operator * (double value, Vector3 rhs);

			///<summary>
			/// Divides the <see cref="Vector3"/> by specified scalar <paramref name="value"/>
			///</summary>
			static Vector3 operator / (Vector3 lhs, double value);

			///<summary>
			/// Return a new unit <see cref="Vector3"/> corresponding to the same direction as this one.
			///</summary>
			///<returns>A unit length vector.</returns>
			Vector3 Normalized( );

			///<summary>
			/// Calculates the dot product of the <see cref="Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
			///</summary>
			///<returns>The dot product.</returns>
			static double DotProduct(Vector3 lhs, Vector3 rhs);

			///<summary>
			/// Calculates the cross product of the <see cref="Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
			///</summary>
			///<returns>A new vector representing the cross product.</returns>
			static Vector3 CrossProduct(Vector3 lhs, Vector3 rhs);

			///<summary>
			/// Calculates the angle between the <see cref="Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
			///</summary>
			///<returns>The angle in radians.</returns>
			static double AngleTo(Vector3 lhs, Vector3 rhs);
		};
	}
}
