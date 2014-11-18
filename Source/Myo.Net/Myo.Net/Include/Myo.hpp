#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

#include <myo/libmyo.h>

#include "MyoEventArgs.hpp"
#include "AccelerometerDataEventArgs.hpp"
#include "OrientationDataEventArgs.hpp"
#include "GyroscopeDataEventArgs.hpp"
#include "RssiDataEventArgs.hpp"
#include "PoseEventArgs.hpp"

namespace Thalmic
{
	namespace Myo
	{
		///<summary>
		/// Types of vibration supported by the Myo. 
		///</summary>
		public enum class VibrationType
		{
			Short,
			Medium,
			Long,
		};

		///<summary>
		/// Structure representing the firmware version of Myo.
		///</summary>
		public value struct FirmwareVersion sealed
		{
			///<summary>
			/// Myo's major version must match the required major version.
			///</summary>
			initonly unsigned int FirmwareVersionMajor;
			
			///<summary>
			/// Myo's minor version must match the required minor version.
			///</summary>
			initonly unsigned int FirmwareVersionMinor;
			
			///<summary>
			/// Myo's patch version must greater or equal to the required patch version.
			///</summary>
			initonly unsigned int FirmwareVersionPatch; 
			
			///<summary>
			/// Myo's hardware revision; not used to detect firmware version mismatch.
			///</summary>
			initonly unsigned int FirmwareVersionHardwareRev;

		internal:

			///<summary>
			/// Initializes a new instance of <see cref="FirmwareVersion"/> with specified integers.
			///</summary>
			FirmwareVersion(unsigned int major, unsigned int minor, unsigned int patch, unsigned int revision)
				: FirmwareVersionMajor(major)
				, FirmwareVersionMinor(minor)
				, FirmwareVersionPatch(patch)
				, FirmwareVersionHardwareRev(revision) { }

		public:
			virtual String^ ToString( ) override {
				return String::Format("{0}.{1}.{2}.{3}",
					FirmwareVersionMajor,
					FirmwareVersionMinor,
					FirmwareVersionPatch,
					FirmwareVersionHardwareRev);
			}
		};

		///<summary>
		/// Interface to a instance of a Myo device.
		///</summary>
		public interface class IMyo : public IDisposable
		{
			///<summary>
			/// Gets the assigned name of the <see cref="Myo"/>.
			///</summary>
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			property String^ Name { String^ get( ); }
			
			///<summary>
			/// Gets the Mac Address of the <see cref="Myo"/>.
			///</summary>
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			property String^ MacAddress { String^ get( ); }
			
			///<summary>
			/// Gets the <see cref="FirmwareVersion"/> of the <see cref="Myo"/>.
			///</summary>
			property Thalmic::Myo::FirmwareVersion^ FirmwareVersion { Thalmic::Myo::FirmwareVersion^ get( ); }

			///<summary>
			/// Occurs when a paired Myo has provided new orientation data. 
			///</summary>
			event EventHandler<OrientationDataEventArgs^>^ OrientationDataAcquired;
			
			///<summary>
			/// Occurs when a paired Myo has provided new accelerometer data in units of g.
			///</summary>
			event EventHandler<AccelerometerDataEventArgs^>^ AccelerometerDataAcquired;
			
			///<summary>
			/// Occurs when a paired Myo has provided new gyroscope data in units of deg/s. 
			///</summary>
			event EventHandler<GyroscopeDataEventArgs^>^ GyroscopeDataAquired;
			
			///<summary>
			/// Occurs when a paired Myo has provided a new RSSI value.
			///</summary>
			event EventHandler<RssiDataEventArgs^>^ Rssi;
			
			///<summary>
			/// Occurs when a paired Myo has provided a new pose. 
			///</summary>
			event EventHandler<PoseEventArgs^>^ Pose;
			
			///<summary>
			/// Engage the Myo's built in vibration motor.
			///</summary>
			///<params>
			///<param name="type">The type of vibration.</param>
			///</params>
			void Vibrate(VibrationType type);
			
			///<summary>
			/// Request the RSSI of the Myo.
			///</summary>
			void RequestRssi( );
		};

		///<summary>
		/// Represents a physical Thalmic Labs(TM) Myo(TM) Device.
		///</summary>
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
			///<summary>
			/// Initializes a new instance of <see cref="Myo"/>.
			///</summary>
			Myo(libmyo_myo_t opaque);
			~Myo( );

			///<summary>
			/// Gets the assigned name of the <see cref="Myo"/>.
			///</summary>
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			virtual property String^ Name { String^ get( ) { throw gcnew NotImplementedException( ); } }
			
			///<summary>
			/// Gets the Mac Address of the <see cref="Myo"/>.
			///</summary>
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			[System::Diagnostics::DebuggerBrowsableAttribute(System::Diagnostics::DebuggerBrowsableState::Never)]
			virtual property String^ MacAddress { String^ get( ) { throw gcnew NotImplementedException( ); } }
			
			///<summary>
			/// Gets the <see cref="FirmwareVersion"/> of the <see cref="Myo"/>.
			///</summary>
			virtual property Thalmic::Myo::FirmwareVersion^ FirmwareVersion { Thalmic::Myo::FirmwareVersion^ get( ) { return _firmware; } }

			///<summary>
			/// Occurs when a paired Myo has provided new orientation data. 
			///</summary>
			virtual event EventHandler<OrientationDataEventArgs^>^ OrientationDataAcquired;
			
			///<summary>
			/// Occurs when a paired Myo has provided new accelerometer data in units of g.
			///</summary>
			virtual event EventHandler<AccelerometerDataEventArgs^>^ AccelerometerDataAcquired;
			
			///<summary>
			/// Occurs when a paired Myo has provided new gyroscope data in units of deg/s. 
			///</summary>
			virtual event EventHandler<GyroscopeDataEventArgs^>^ GyroscopeDataAquired;
			
			///<summary>
			/// Occurs when a paired Myo has provided a new RSSI value.
			///</summary>
			virtual event EventHandler<RssiDataEventArgs^>^ Rssi;
			
			///<summary>
			/// Occurs when a paired Myo has provided a new pose. 
			///</summary>
			virtual event EventHandler<PoseEventArgs^>^ Pose;
			
			///<summary>
			/// Engage the Myo's built in vibration motor.
			///</summary>
			///<params>
			///<param name="type">The type of vibration.</param>
			///</params>
			virtual void Vibrate(VibrationType type);
			
			///<summary>
			/// Request the RSSI of the Myo.
			///</summary>
			virtual void RequestRssi( );
		};
	}
}

