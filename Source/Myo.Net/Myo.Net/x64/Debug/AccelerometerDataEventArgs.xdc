<?xml version="1.0"?><doc>
<members>
<member name="M:Thalmic.Myo.MyoEventArgs.#ctor(Thalmic.Myo.IMyo,System.DateTimeOffset)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myoeventargs.hpp" line="20">
<summary>
Initializes a new instance of <see cref="T:Thalmic.Myo.MyoEventArgs"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.MyoEventArgs.Myo" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myoeventargs.hpp" line="26">
<summary>
Gets the <see cref="T:Thalmic.Myo.IMyo"/> associated with the event.
</summary>
</member>
<member name="P:Thalmic.Myo.MyoEventArgs.TimeStamp" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myoeventargs.hpp" line="31">
<summary>
Gets the time stamp at which the event occurred.
</summary>
</member>
<member name="T:Thalmic.Myo.Vector3" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="7">
<summary>
A vector of three components.
</summary>
</member>
<member name="F:Thalmic.Myo.Vector3.Zero" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="20">
<summary>
Represents a 3-dimension vector that has X, Y, and Z values set to zero.
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.#ctor(System.Double,System.Double,System.Double)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="25">
<summary>
Initializes a new instance of the <see cref="T:Thalmic.Myo.Vector3"/> with the specified components.
</summary>
<params>
<param name="x">The x component of the <see cref="T:Thalmic.Myo.Vector3"/>.</param>
<param name="y">The y component of the <see cref="T:Thalmic.Myo.Vector3"/>.</param>
<param name="z">The z component of the <see cref="T:Thalmic.Myo.Vector3"/>.</param>
</params>
</member>
<member name="P:Thalmic.Myo.Vector3.X" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="35">
<summary>
Gets or sets the x component of the <see cref="T:Thalmic.Myo.Vector3"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Vector3.Y" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="44">
<summary>
Gets or sets the y component of the <see cref="T:Thalmic.Myo.Vector3"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Vector3.Z" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="53">
<summary>
Gets or sets the z component of the <see cref="T:Thalmic.Myo.Vector3"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Vector3.default(System.Int32)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="62">
<summary>
Get or set a component in the <see cref="T:Thalmic.Myo.Vector3"/> by index.
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.Length" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="71">
<summary>
Gets the length of the <see cref="T:Thalmic.Myo.Vector3"/>
</summary>
<returns>The length of the <see cref="T:Thalmic.Myo.Vector3"/>.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.LengthSquared" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="77">
<summary>
Gets the length squared of the <see cref="T:Thalmic.Myo.Vector3"/>
</summary>
<returns>The squared length of the <see cref="T:Thalmic.Myo.Vector3"/>.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Addition(Thalmic.Myo.Vector3,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="83">
<summary>
Adds the specified <see cref="T:Thalmic.Myo.Vector3"/>'s.
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Subtraction(Thalmic.Myo.Vector3,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="88">
<summary>
Subtracts a <see cref="T:Thalmic.Myo.Vector3"/> from another.
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Multiply(Thalmic.Myo.Vector3,System.Double)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="93">
<summary>
Multiplies the <see cref="T:Thalmic.Myo.Vector3"/> by specified scalar <paramref name="value"/>
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Multiply(System.Double,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="98">
<summary>
Multiplies the <see cref="T:Thalmic.Myo.Vector3"/> by specified scalar <paramref name="value"/>
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Division(Thalmic.Myo.Vector3,System.Double)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="103">
<summary>
Divides the <see cref="T:Thalmic.Myo.Vector3"/> by specified scalar <paramref name="value"/>
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.Normalized" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="108">
<summary>
Return a new unit <see cref="T:Thalmic.Myo.Vector3"/> corresponding to the same direction as this one.
</summary>
<returns>A unit length vector.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.DotProduct(Thalmic.Myo.Vector3,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="114">
<summary>
Calculates the dot product of the <see cref="T:Thalmic.Myo.Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
</summary>
<returns>The dot product.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.CrossProduct(Thalmic.Myo.Vector3,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="120">
<summary>
Calculates the cross product of the <see cref="T:Thalmic.Myo.Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
</summary>
<returns>A new vector representing the cross product.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.AngleTo(Thalmic.Myo.Vector3,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="126">
<summary>
Calculates the angle between the <see cref="T:Thalmic.Myo.Vector3"/>'s <paramref name="lhs"/> and <paramref name="rhs"/>.
</summary>
<returns>The angle in radians.</returns>
</member>
</members>
</doc>