<?xml version="1.0"?><doc>
<members>
<member name="P:Thalmic.Myo.MyoEventArgs.Myo" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myoeventargs.hpp" line="23">
<summary>
Gets the <see cref="T:Thalmic.Myo.IMyo"/> associated with the event.
</summary>
</member>
<member name="P:Thalmic.Myo.MyoEventArgs.TimeStamp" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myoeventargs.hpp" line="28">
<summary>
Gets the time stamp at which the event occurred.
</summary>
</member>
<member name="T:Thalmic.Myo.Quaternion" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="9">
<summary>
Structure that represents a rotation in three dimensions.
</summary>
</member>
<member name="F:Thalmic.Myo.Quaternion.Zero" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="23">
<summary>
Represents a quaternion that has X, Y, Z and W values set to zero.
</summary>
</member>
<member name="P:Thalmic.Myo.Quaternion.X" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="28">
<summary>
Gets or sets the x component of the <see cref="T:Thalmic.Myo.Quaternion"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Quaternion.Y" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="37">
<summary>
Gets or sets the y component of the <see cref="T:Thalmic.Myo.Quaternion"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Quaternion.Z" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="46">
<summary>
Gets or sets the z component of the <see cref="T:Thalmic.Myo.Quaternion"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Quaternion.W" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="55">
<summary>
Gets or sets the w component of the <see cref="T:Thalmic.Myo.Quaternion"/>.
</summary>
</member>
<member name="M:Thalmic.Myo.Quaternion.#ctor(System.Double,System.Double,System.Double,System.Double)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="64">
<summary>
Initializes a new instance of the <see cref="T:Thalmic.Myo.Quaternion"/> with the specified components.
</summary>
<params>
<param name="x">The x component of the <see cref="T:Thalmic.Myo.Quaternion"/>.</param>
<param name="y">The y component of the <see cref="T:Thalmic.Myo.Quaternion"/>.</param>
<param name="z">The z component of the <see cref="T:Thalmic.Myo.Quaternion"/>.</param>
<param name="w">The w component of the <see cref="T:Thalmic.Myo.Quaternion"/>.</param>
</params>
</member>
<member name="P:Thalmic.Myo.Quaternion.default(System.Int32)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="75">
<summary>
Get or set a component in the <see cref="T:Thalmic.Myo.Quaternion"/> by index.
</summary>
</member>
<member name="M:Thalmic.Myo.Quaternion.Length" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="84">
<summary>
Gets the length of the <see cref="T:Thalmic.Myo.Quaternion"/>
</summary>
<returns>The length of the <see cref="T:Thalmic.Myo.Quaternion"/>.</returns>
</member>
<member name="M:Thalmic.Myo.Quaternion.LengthSquared" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="90">
<summary>
Gets the length squared of the <see cref="T:Thalmic.Myo.Quaternion"/>
</summary>
<returns>The squared length of the <see cref="T:Thalmic.Myo.Quaternion"/>.</returns>
</member>
<member name="M:Thalmic.Myo.Quaternion.Roll(Thalmic.Myo.Quaternion)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="96">
<summary>
Calculate the roll angle represented by the given unit <see cref="T:Thalmic.Myo.Quaternion"/>.
</summary>
<params>
<param name="quat">A unit <see cref="T:Thalmic.Myo.Quaternion"/>.</param>
</params>
<returns>The roll angle in radians.</returns>
</member>
<member name="M:Thalmic.Myo.Quaternion.Pitch(Thalmic.Myo.Quaternion)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="105">
<summary>
Calculate the pitch angle represented by the given unit <see cref="T:Thalmic.Myo.Quaternion"/>.
</summary>
<params>
<param name="quat">A unit <see cref="T:Thalmic.Myo.Quaternion"/>.</param>
</params>
<returns>The pitch angle in radians.</returns>
</member>
<member name="M:Thalmic.Myo.Quaternion.Yaw(Thalmic.Myo.Quaternion)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="114">
<summary>
Calculate the yaw angle represented by the given unit <see cref="T:Thalmic.Myo.Quaternion"/>.
</summary>
<params>
<param name="quat">A unit <see cref="T:Thalmic.Myo.Quaternion"/>.</param>
</params>
<returns>The yaw angle in radians.</returns>
</member>
<member name="M:Thalmic.Myo.Quaternion.op_Addition(Thalmic.Myo.Quaternion,Thalmic.Myo.Quaternion)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="123">
<summary>
Adds the specified <see cref="T:Thalmic.Myo.Quaternion"/>'s.
</summary>
</member>
<member name="M:Thalmic.Myo.Quaternion.op_Subtraction(Thalmic.Myo.Quaternion,Thalmic.Myo.Quaternion)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="128">
<summary>
Subtracts a <see cref="T:Thalmic.Myo.Quaternion"/> from another.
</summary>
</member>
<member name="M:Thalmic.Myo.Quaternion.op_Multiply(Thalmic.Myo.Quaternion,Thalmic.Myo.Quaternion)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="133">
<summary>
Multiplies the specified <see cref="T:Thalmic.Myo.Quaternion"/>'s.
</summary>
</member>
<member name="M:Thalmic.Myo.Quaternion.Inverse" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="138">
<summary>
Gets the inverse of the <see cref="T:Thalmic.Myo.Quaternion"/>.
</summary>
</member>
<member name="M:Thalmic.Myo.Quaternion.Normalized" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\quaternion.hpp" line="143">
<summary>
Return a new unit <see cref="T:Thalmic.Myo.Quaternion"/> corresponding to the same rotation as this one.
</summary>
</member>
</members>
</doc>