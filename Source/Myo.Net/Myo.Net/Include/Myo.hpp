#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

#include <myo/libmyo.h>

#include "MyoEventArgs.hpp"
#include "AccelerometerDataEventArgs.hpp"
#include "OrientationDataEventArgs.hpp"
#include "GyroscopeDataEventArgs.hpp"
#include "RssiDataEventArgs.hpp"
#include "PoseChangedEventArgs.hpp"
#include "RecognizedArmEventArgs.hpp"

#include "FirmwareVersion.hpp"

namespace MyoNet
{
	namespace Myo
	{
		/// <summary>
		/// Types of vibration supported by the Myo. 
		/// </summary>
		public enum class VibrationType
		{
			Short = libmyo_vibration_short,
			Medium = libmyo_vibration_medium,
			Long = libmyo_vibration_long,
		};

		/// <summary>
		/// Unlock types support by Myo. 
		/// </summary>
		public enum class UnlockType
		{
			Timed = libmyo_unlock_timed,
			Hold = libmyo_unlock_hold,
		};
		

		/// <summary>
		/// Interface to a instance of a Myo device.
		/// </summary>
		public interface class IMyo : public IDisposable
		{
			/// <summary>
			/// Gets the assigned name of the <see cref="Myo"/>.
			/// </summary>
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			property String^ Name { String^ get( ); }
			
			/// <summary>
			/// Gets the Mac Address of the <see cref="Myo"/>.
			/// </summary>
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			property String^ MacAddress { String^ get( ); }
			
			/// <summary>
			/// Gets the <see cref="FirmwareVersion"/> of the <see cref="Myo"/>.
			/// </summary>
			property MyoNet::Myo::FirmwareVersion FirmwareVersion { MyoNet::Myo::FirmwareVersion get( ); }

			/// <summary>
			/// Occurs when a paired Myo has provided new orientation data. 
			/// </summary>
			event EventHandler<OrientationDataEventArgs^>^ OrientationDataAcquired;
			
			/// <summary>
			/// Occurs when a paired Myo has provided new accelerometer data in units of g.
			/// </summary>
			event EventHandler<AccelerometerDataEventArgs^>^ AccelerometerDataAcquired;
			
			/// <summary>
			/// Occurs when a paired Myo has provided new gyroscope data in units of deg/s. 
			/// </summary>
			event EventHandler<GyroscopeDataEventArgs^>^ GyroscopeDataAquired;
			
			/// <summary>
			/// Occurs when a paired Myo has provided a new RSSI value.
			/// </summary>
			event EventHandler<RssiDataEventArgs^>^ Rssi;
			
			/// <summary>
			/// Occurs when a paired Myo has provided a new pose. 
			/// </summary>
			event EventHandler<PoseChangedEventArgs^>^ PoseChanged;

			/// <summary>
			/// Occurs when a paired Myo recognizes that it is on an arm. 
			/// </summary>
			event EventHandler<RecognizedArmEventArgs^>^ RecognizedArm;

			/// <summary>
			/// Occurs when a paired Myo recognizes that it is on an arm. 
			/// </summary>
			event EventHandler<MyoEventArgs^>^ LostArm;

			/// <summary>
			/// Occurs when a paired Myo becomes unlocked.
			/// </summary>
			event EventHandler<MyoEventArgs^>^ Unlocked;

			/// <summary>
			/// Occurs when a paired Myo becomes locked.
			/// </summary>
			event EventHandler<MyoEventArgs^>^ Locked;
			
			/// <summary>
			/// Engage the Myo's built in vibration motor.
			/// </summary>
			/// <params>
			/// <param name="type">The type of vibration.</param>
			/// </params>
			void Vibrate(VibrationType type);
			
			/// <summary>
			/// Request the RSSI of the Myo.
			/// </summary>
			void RequestRssi( );

			/// <summary>Unlock the Myo.</summary>
			/// <remarks>
			/// Myo will remain unlocked for a short amount of time, after which it will automatically lock again.
			/// If Myo was locked, an Unlock event will be generated.
			/// </remarks>
			virtual void Unlock(UnlockType type);

			/// <summary>
			/// Force the Myo to lock immediately.
			/// </summary>
			/// <remarks>
			/// Will cause Myo to vibrate.
			/// </remarks>
			virtual void Lock( );

			/// <summary>
			/// Notify the Myo that a user action was recognized.
			/// </summary>
			virtual void NotifyUserAction( );
		};

		/// <summary>
		/// Represents a physical MyoNet Labs(TM) Myo(TM) Device.
		/// </summary>
		private ref class Myo : public IMyo
		{
		private:
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			libmyo_myo_t _myo;

			FirmwareVersion _firmware;

		internal:
			void _OnDeviceEvent(libmyo_event_t ev);
			void _SetFirmwareVersion(FirmwareVersion version);

			libmyo_myo_t _libmyoObject( ) { return _myo; }

		public:
			/// <summary>
			/// Initializes a new instance of <see cref="Myo"/>.
			/// </summary>
			Myo(libmyo_myo_t opaque);
			~Myo( );

			/// <summary>
			/// Gets the assigned name of the <see cref="Myo"/>.
			/// </summary>
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			virtual property String^ Name { String^ get( ) { throw gcnew NotImplementedException( ); } }
			
			/// <summary>
			/// Gets the Mac Address of the <see cref="Myo"/>.
			/// </summary>
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			virtual property String^ MacAddress { String^ get( ) { throw gcnew NotImplementedException( ); } }
			
			/// <summary>
			/// Gets the <see cref="FirmwareVersion"/> of the <see cref="Myo"/>.
			/// </summary>
			virtual property MyoNet::Myo::FirmwareVersion FirmwareVersion { MyoNet::Myo::FirmwareVersion get( ) { return _firmware; } }

			/// <summary>
			/// Occurs when a paired Myo has provided new orientation data. 
			/// </summary>
			virtual event EventHandler<OrientationDataEventArgs^>^ OrientationDataAcquired;
			
			/// <summary>
			/// Occurs when a paired Myo has provided new accelerometer data in units of g.
			/// </summary>
			virtual event EventHandler<AccelerometerDataEventArgs^>^ AccelerometerDataAcquired;
			
			/// <summary>
			/// Occurs when a paired Myo has provided new gyroscope data in units of deg/s. 
			/// </summary>
			virtual event EventHandler<GyroscopeDataEventArgs^>^ GyroscopeDataAquired;
			
			/// <summary>
			/// Occurs when a paired Myo has provided a new RSSI value.
			/// </summary>
			virtual event EventHandler<RssiDataEventArgs^>^ Rssi;
			
			/// <summary>
			/// Occurs when a paired Myo has provided a new pose. 
			/// </summary>
			virtual event EventHandler<PoseChangedEventArgs^>^ PoseChanged;

			/// <summary>
			/// Occurs when a paired Myo recognizes that it is on an arm. 
			/// </summary>
			virtual event EventHandler<RecognizedArmEventArgs^>^ RecognizedArm;

			/// <summary>
			/// Occurs when a paired Myo recognizes that it is on an arm. 
			/// </summary>
			virtual event EventHandler<MyoEventArgs^>^ LostArm;

			/// <summary>
			/// Occurs when a paired Myo becomes unlocked.
			/// </summary>
			virtual event EventHandler<MyoEventArgs^>^ Unlocked;

			/// <summary>
			/// Occurs when a paired Myo becomes locked.
			/// </summary>
			virtual event EventHandler<MyoEventArgs^>^ Locked;
			
			/// <summary>
			/// Engage the Myo's built in vibration motor.
			/// </summary>
			/// <params>
			/// <param name="type">The type of vibration.</param>
			/// </params>
			virtual void Vibrate(VibrationType type);
			
			/// <summary>
			/// Request the RSSI of the Myo.
			/// </summary>
			virtual void RequestRssi( );


			/// <summary>Unlock the Myo.</summary>
			/// <remarks>
			/// Myo will remain unlocked for a short amount of time, after which it will automatically lock again.
			/// If Myo was locked, an onUnlock event will be generated.
			/// </remarks>
			virtual void Unlock(UnlockType type);

			/// <summary>
			/// Force the Myo to lock immediately.
			/// </summary>
			/// <remarks>
			/// Will cause Myo to vibrate.
			/// </remarks>
			virtual void Lock( );

			/// <summary>
			/// Notify the Myo that a user action was recognized.
			/// </summary>
			virtual void NotifyUserAction( );
		};
	}
}

