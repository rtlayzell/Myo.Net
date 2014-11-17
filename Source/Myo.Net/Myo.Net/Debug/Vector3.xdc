<?xml version="1.0"?><doc>
<members>
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
<member name="T:myo.Arm" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="17">
Enumeration identifying a right arm or left arm.
</member>
<member name="T:myo.XDirection" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="24">
Possible directions for Myo's +x axis relative to a user's arm.
</member>
<member name="T:myo.FirmwareVersion" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="31">
Firmware version of Myo.
</member>
<member name="T:myo.DeviceListener" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="39">
A DeviceListener receives events about a Myo.
@see Hub::addListener()
</member>
<member name="M:myo.DeviceListener.onPair(myo.Myo*,System.UInt64,myo.FirmwareVersion)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="45">
Called when a Myo has been paired.
</member>
<member name="M:myo.DeviceListener.onUnpair(myo.Myo*,System.UInt64)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="48">
Called when a Myo has been unpaired.
</member>
<member name="M:myo.DeviceListener.onConnect(myo.Myo*,System.UInt64,myo.FirmwareVersion)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="51">
Called when a paired Myo has been connected.
</member>
<member name="M:myo.DeviceListener.onDisconnect(myo.Myo*,System.UInt64)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="54">
Called when a paired Myo has been disconnected.
</member>
<member name="M:myo.DeviceListener.onArmSync(myo.Myo*,System.UInt64,myo.Arm,myo.XDirection)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="57">
Called when a paired Myo recognizes that it is on an arm.
</member>
<member name="M:myo.DeviceListener.onArmUnsync(myo.Myo*,System.UInt64)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="60">
Called when a paired Myo is moved or removed from the arm.
</member>
<member name="M:myo.DeviceListener.onPose(myo.Myo*,System.UInt64,myo.Pose)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="63">
Called when a paired Myo has provided a new pose.
</member>
<member name="M:myo.DeviceListener.onOrientationData(myo.Myo*,System.UInt64,myo.Quaternion&lt;System.Single&gt;!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="66">
Called when a paired Myo has provided new orientation data.
</member>
<member name="M:myo.DeviceListener.onAccelerometerData(myo.Myo*,System.UInt64,myo.Vector3&lt;System.Single&gt;!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="69">
Called when a paired Myo has provided new accelerometer data in units of g.
</member>
<member name="M:myo.DeviceListener.onGyroscopeData(myo.Myo*,System.UInt64,myo.Vector3&lt;System.Single&gt;!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="72">
Called when a paired Myo has provided new gyroscope data in units of deg/s.
</member>
<member name="M:myo.DeviceListener.onRssi(myo.Myo*,System.UInt64,System.SByte)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="75">
Called when a paired Myo has provided a new RSSI value.
@see Myo::requestRssi() to request an RSSI value from the Myo.
</member>
<member name="M:myo.DeviceListener.onOpaqueEvent(System.Void!System.Runtime.CompilerServices.IsConst*)" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\devicelistener.hpp" line="79">
@cond LIBMYO_INTERNALS
</member>
<member name="T:myo.Hub" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="14">
@brief A Hub provides access to one or more Myo instances.
</member>
<member name="M:myo.Hub.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="17">
Construct a hub.
\a applicationIdentifier must follow a reverse domain name format (ex. com.domainname.appname). Application
identifiers can be formed from the set of alphanumeric ASCII characters (a-z, A-Z, 0-9). The hyphen (-) and
underscore (_) characters are permitted if they are not adjacent to a period (.) character  (i.e. not at the
start or end of each segment), but are not permitted in the top-level domain. Application identifiers must have
three or more segments. For example, if a company's domain is example.com and the application is named
hello-world, one could use "com.example.hello-world" as a valid application identifier. \a applicationIdentifier
can be an empty string.
Throws an exception of type std::invalid_argument if \a applicationIdentifier is not in the proper reverse
domain name format or is longer than 255 characters.
Throws an exception of type std::runtime_error if the hub initialization failed for some reason, typically
because Myo Connect is not running and a connection can thus not be established.
</member>
<member name="M:myo.Hub.Dispose" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="31">
Deallocate any resources associated with a Hub.
This will cause all Myo instances retrieved from this Hub to become invalid.
</member>
<member name="M:myo.Hub.waitForMyo(System.UInt32)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="35">
Wait for a Myo to become paired, or time out after \a timeout_ms milliseconds if provided.
If \a timeout_ms is zero, this function blocks until a Myo is found.
This function must not be called concurrently with run() or runOnce().
</member>
<member name="M:myo.Hub.addListener(myo.DeviceListener*)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="40">
Register a listener to be called when device events occur.
</member>
<member name="M:myo.Hub.removeListener(myo.DeviceListener*)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="43">
Remove a previously registered listener.
</member>
<member name="M:myo.Hub.run(System.UInt32)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="46">
Run the event loop for the specified duration (in milliseconds).
</member>
<member name="M:myo.Hub.runOnce(System.UInt32)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="49">
Run the event loop until a single event occurs, or the specified duration (in milliseconds) has elapsed.
</member>
<member name="M:myo.Hub.libmyoObject" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="52">
@cond MYO_INTERNALS
Return the internal libmyo object corresponding to this hub.
</member>
<member name="M:myo.Hub.#ctor(myo.Hub!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\hub.hpp" line="68">
@endcond
</member>
<member name="T:myo.Myo" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\myo.hpp" line="9">
Represents a Myo device with a specific MAC address.
This class can not be instantiated directly; instead, use Hub to get access to a Myo.
There is only one Myo instance corresponding to each device; thus, if the addresses of two Myo instances compare
equal, they refer to the same device.
</member>
<member name="T:myo.Myo.VibrationType" decl="false" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\myo.hpp" line="15">
Types of vibration supported by the Myo.
</member>
<member name="M:myo.Myo.vibrate(myo.Myo.VibrationType)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\myo.hpp" line="22">
Vibrate the Myo.
</member>
<member name="M:myo.Myo.requestRssi" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\myo.hpp" line="25">
Request the RSSI of the Myo. An onRssi event will likely be generated with the value of the RSSI.
@see DeviceListener::onRssi()
</member>
<member name="M:myo.Myo.libmyoObject" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\myo.hpp" line="29">
@cond MYO_INTERNALS
Return the internal libmyo object corresponding to this device.
</member>
<member name="M:myo.Myo.#ctor(System.Void*)" decl="true" source="d:\projects\myo.net\source\myo.net\myo.net\include\myo\cxx\myo.hpp" line="34">
@endcond
</member>
</members>
</doc>