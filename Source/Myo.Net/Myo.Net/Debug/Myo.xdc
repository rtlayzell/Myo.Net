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
<member name="M:Thalmic.Myo.Vector3.Length" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="70">
<summary>
Gets the length of the <see cref="T:Thalmic.Myo.Vector3"/>
</summary>
<returns>The length of the <see cref="T:Thalmic.Myo.Vector3"/>.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.LengthSquared" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="76">
<summary>
Gets the length squared of the <see cref="T:Thalmic.Myo.Vector3"/>
</summary>
<returns>The squared length of the <see cref="T:Thalmic.Myo.Vector3"/>.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Addition(Thalmic.Myo.Vector3,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="82">
<summary>
Adds the specified <see cref="T:Thalmic.Myo.Vector3"/>'s.
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Subtraction(Thalmic.Myo.Vector3,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="87">
<summary>
Subtracts a <see cref="T:Thalmic.Myo.Vector3"/> from another.
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Multiply(Thalmic.Myo.Vector3,System.Double)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="92">
<summary>
Multiplies the <see cref="T:Thalmic.Myo.Vector3"/> by specified scalar <paramref name="value"/>
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Multiply(System.Double,Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="97">
<summary>
Multiplies the <see cref="T:Thalmic.Myo.Vector3"/> by specified scalar <paramref name="value"/>
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.op_Division(Thalmic.Myo.Vector3,System.Double)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="102">
<summary>
Divides the <see cref="T:Thalmic.Myo.Vector3"/> by specified scalar <paramref name="value"/>
</summary>
</member>
<member name="M:Thalmic.Myo.Vector3.Normalized" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="107">
<summary>
Return a new unit <see cref="T:Thalmic.Myo.Vector3"/> corresponding to the same direction as this one.
</summary>
<returns>A unit length vector.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.Dot(Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="113">
<summary>
Calculates the dot product of this <see cref="T:Thalmic.Myo.Vector3"/> and <paramref name="rhs"/>.
</summary>
<returns>The dot product.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.Cross(Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="119">
<summary>
Calculates the cross product of this <see cref="T:Thalmic.Myo.Vector3"/> and <paramref name="rhs"/>.
</summary>
<returns>A new vector representing the cross product.</returns>
</member>
<member name="M:Thalmic.Myo.Vector3.AngleTo(Thalmic.Myo.Vector3)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\vector3.hpp" line="125">
<summary>
Calculates the angle between this <see cref="T:Thalmic.Myo.Vector3"/> and <paramref name="rhs"/>.
</summary>
<returns>The angle in radians.</returns>
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
<member name="T:myo.Pose" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="12">
A pose represents a detected configuration of the user's hand.
</member>
<member name="T:myo.Pose.Type" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="15">
Types of poses supported by the SDK.
</member>
<member name="M:myo.Pose.#ctor" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="27">
Construct a pose of type Pose::none.
</member>
<member name="M:myo.Pose.#ctor(myo.Pose.Type)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="30">
Construct a pose with the given type.
</member>
<member name="M:myo.Pose.op_Equality(myo.Pose)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="33">
Returns true if and only if the two poses are of the same type.
</member>
<member name="M:myo.Pose.op_Inequality(myo.Pose)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="36">
Equivalent to `!(*this == other)`.
</member>
<member name="M:myo.Pose.type" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="39">
Returns the type of this pose.
</member>
<member name="M:myo.Pose.toString" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="42">
Return a human-readable string representation of the pose.
</member>
<member name="M:myo.op_Equality(myo.Pose,myo.Pose.Type)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="49">
@relates Pose
Returns true if and only if the type of pose is the same as the provided type.
</member>
<member name="M:myo.op_Equality(myo.Pose.Type,myo.Pose)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="53">
@relates Pose
Equivalent to `pose == type`.
</member>
<member name="M:myo.op_Inequality(myo.Pose,myo.Pose.Type)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="57">
@relates Pose
Equivalent to `!(pose == type)`.
</member>
<member name="M:myo.op_Inequality(myo.Pose.Type,myo.Pose)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="61">
@relates Pose
Equivalent to `!(type == pose)`.
</member>
<member name="M:myo.op_LeftShift(std.basic_ostream&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte}&gt;*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,myo.Pose!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\pose.hpp" line="65">
@relates Pose
Write the name of the provided pose to the provided output stream.
</member>
<member name="T:Thalmic.Myo.Pose" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\pose.hpp" line="10">
<summary>
Types of poses supported by the SDK. 
</summary>
</member>
<member name="T:Thalmic.Myo.VibrationType" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="20">
<summary>
Types of vibration supported by the Myo. 
</summary>
</member>
<member name="T:Thalmic.Myo.FirmwareVersion" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="30">
<summary>
Structure representing the firmware version of Myo.
</summary>
</member>
<member name="F:Thalmic.Myo.FirmwareVersion.FirmwareVersionMajor" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="35">
<summary>
Myo's major version must match the required major version.
</summary>
</member>
<member name="F:Thalmic.Myo.FirmwareVersion.FirmwareVersionMinor" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="40">
<summary>
Myo's minor version must match the required minor version.
</summary>
</member>
<member name="F:Thalmic.Myo.FirmwareVersion.FirmwareVersionPatch" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="45">
<summary>
Myo's patch version must greater or equal to the required patch version.
</summary>
</member>
<member name="F:Thalmic.Myo.FirmwareVersion.FirmwareVersionHardwareRev" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="50">
<summary>
Myo's hardware revision; not used to detect firmware version mismatch.
</summary>
</member>
<member name="M:Thalmic.Myo.FirmwareVersion.#ctor(System.UInt32,System.UInt32,System.UInt32,System.UInt32)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="57">
<summary>
Initializes a new instance of <see cref="T:Thalmic.Myo.FirmwareVersion"/> with specified integers.
</summary>
</member>
<member name="T:Thalmic.Myo.IMyo" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="76">
<summary>
Interface to a instance of a Myo device.
</summary>
</member>
<member name="P:Thalmic.Myo.IMyo.Name" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="81">
<summary>
Gets the assigned name of the <see cref="N:Thalmic.Myo"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.IMyo.MacAddress" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="88">
<summary>
Gets the Mac Address of the <see cref="N:Thalmic.Myo"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.IMyo.FirmwareVersion" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="95">
<summary>
Gets the <see cref="P:Thalmic.Myo.IMyo.FirmwareVersion"/> of the <see cref="N:Thalmic.Myo"/>.
</summary>
</member>
<member name="E:Thalmic.Myo.IMyo.OrientationDataAcquired" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="100">
<summary>
Occurs when a paired Myo has provided new orientation data. 
</summary>
</member>
<member name="E:Thalmic.Myo.IMyo.AccelerometerDataAcquired" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="105">
<summary>
Occurs when a paired Myo has provided new accelerometer data in units of g.
</summary>
</member>
<member name="E:Thalmic.Myo.IMyo.GyroscopeDataAquired" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="110">
<summary>
Occurs when a paired Myo has provided new gyroscope data in units of deg/s. 
</summary>
</member>
<member name="E:Thalmic.Myo.IMyo.Rssi" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="115">
<summary>
Occurs when a paired Myo has provided a new RSSI value.
</summary>
</member>
<member name="E:Thalmic.Myo.IMyo.Pose" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="120">
<summary>
Occurs when a paired Myo has provided a new pose. 
</summary>
</member>
<member name="M:Thalmic.Myo.IMyo.Vibrate(Thalmic.Myo.VibrationType)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="125">
<summary>
Engage the Myo's built in vibration motor.
</summary>
<params>
<param name="type">The type of vibration.</param>
</params>
</member>
<member name="M:Thalmic.Myo.IMyo.RequestRssi" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="133">
<summary>
Request the RSSI of the Myo.
</summary>
</member>
<member name="T:Thalmic.Myo.Myo" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="139">
<summary>
Represents a physical Thalmic Labs(TM) Myo(TM) Device.
</summary>
</member>
<member name="M:Thalmic.Myo.Myo.#ctor(System.Void*)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="158">
<summary>
Initializes a new instance of <see cref="T:Thalmic.Myo.Myo"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Myo.Name" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="164">
<summary>
Gets the assigned name of the <see cref="T:Thalmic.Myo.Myo"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Myo.MacAddress" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="170">
<summary>
Gets the Mac Address of the <see cref="T:Thalmic.Myo.Myo"/>.
</summary>
</member>
<member name="P:Thalmic.Myo.Myo.FirmwareVersion" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="176">
<summary>
Gets the <see cref="P:Thalmic.Myo.Myo.FirmwareVersion"/> of the <see cref="T:Thalmic.Myo.Myo"/>.
</summary>
</member>
<member name="E:Thalmic.Myo.Myo.OrientationDataAcquired" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="181">
<summary>
Occurs when a paired Myo has provided new orientation data. 
</summary>
</member>
<member name="E:Thalmic.Myo.Myo.AccelerometerDataAcquired" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="186">
<summary>
Occurs when a paired Myo has provided new accelerometer data in units of g.
</summary>
</member>
<member name="E:Thalmic.Myo.Myo.GyroscopeDataAquired" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="191">
<summary>
Occurs when a paired Myo has provided new gyroscope data in units of deg/s. 
</summary>
</member>
<member name="E:Thalmic.Myo.Myo.Rssi" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="196">
<summary>
Occurs when a paired Myo has provided a new RSSI value.
</summary>
</member>
<member name="E:Thalmic.Myo.Myo.Pose" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="201">
<summary>
Occurs when a paired Myo has provided a new pose. 
</summary>
</member>
<member name="M:Thalmic.Myo.Myo.Vibrate(Thalmic.Myo.VibrationType)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="206">
<summary>
Engage the Myo's built in vibration motor.
</summary>
<params>
<param name="type">The type of vibration.</param>
</params>
</member>
<member name="M:Thalmic.Myo.Myo.RequestRssi" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo.hpp" line="214">
<summary>
Request the RSSI of the Myo.
</summary>
</member>
</members>
</doc>