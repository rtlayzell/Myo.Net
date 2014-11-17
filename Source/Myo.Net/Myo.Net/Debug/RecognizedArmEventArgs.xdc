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
<member name="T:Thalmic.Myo.Arm" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\arm.hpp" line="10">
<summary>
Enumeration identifying a right arm or left arm.
</summary>
</member>
<member name="T:Thalmic.Myo.XDirection" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\arm.hpp" line="20">
<summary>
Possible directions for Myo's +x axis relative to a user's arm.
</summary>
</member>
</members>
</doc>