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

#include "HashCodeHelper.hpp"

namespace MyoNet
{
	namespace Myo
	{
		/// <summary>
		/// Types of vibration supported by the Myo. 
		/// </summary>
		public enum class VibrationType
		{
			Short,
			Medium,
			Long,
		};

		/// <summary>
		/// Structure representing the firmware version of Myo.
		/// </summary>
		[DebuggerDisplayAttribute("v{ToString(),nq}")]
		public value struct FirmwareVersion sealed : IEquatable<FirmwareVersion>
		{
			/// <summary>
			/// Myo's major version must match the required major version.
			/// </summary>
			initonly unsigned int FirmwareVersionMajor;
			
			/// <summary>
			/// Myo's minor version must match the required minor version.
			/// </summary>
			initonly unsigned int FirmwareVersionMinor;
			
			/// <summary>
			/// Myo's patch version must greater or equal to the required patch version.
			/// </summary>
			initonly unsigned int FirmwareVersionPatch; 
			
			/// <summary>
			/// Myo's hardware revision; not used to detect firmware version mismatch.
			/// </summary>
			initonly unsigned int FirmwareVersionHardwareRev;

		internal:
			/// <summary>
			/// Initializes a new instance of <see cref="FirmwareVersion"/> with specified integers.
			/// </summary>
			FirmwareVersion(unsigned int major, unsigned int minor, unsigned int patch, unsigned int revision)
				: FirmwareVersionMajor(major)
				, FirmwareVersionMinor(minor)
				, FirmwareVersionPatch(patch)
				, FirmwareVersionHardwareRev(revision) { }

		public:

			static bool operator == (FirmwareVersion lhs, FirmwareVersion rhs)
			{
				return lhs.Equals(rhs);
			}

			static bool operator != (FirmwareVersion lhs, FirmwareVersion rhs)
			{
				return !lhs.Equals(rhs);
			}
			
			/// <summary> 
			/// Returns the hash code for this FirmwareVersion instance. 
			/// </summary> 
			/// <returns>The hash code.</returns> 
			virtual int GetHashCode( ) override
			{
				int hash = this->FirmwareVersionMajor.GetHashCode( );
				hash = HashCodeHelper::CombineHashCodes(hash, this->FirmwareVersionMinor.GetHashCode( ));
				hash = HashCodeHelper::CombineHashCodes(hash, this->FirmwareVersionPatch.GetHashCode( ));
				hash = HashCodeHelper::CombineHashCodes(hash, this->FirmwareVersionHardwareRev.GetHashCode( ));

				return hash;
			}

			/// <summary>
			/// Determines whether the specified object is equal to this FirmwareVersion instance.
			/// </summary>
			/// <params>
			/// <param name="obj">The Object to compare against.</param>
			/// </params>
			/// <returns>True if the Object is equal to this FirmwareVersion; False otherwise.</returns>
			bool Equals(Object^ obj) override
			{
				if (dynamic_cast<FirmwareVersion^>(obj) == nullptr)
					return false;
				return this->Equals((FirmwareVersion)obj);
			}

			/// <summary>
			/// Determines whether the specified FirmwareVersion is equal to this FirmwareVersion instance.
			/// </summary>
			/// <params>
			/// <param name="firmwareVersion">The FirmwareVersion to compare against.</param>
			/// </params>
			/// <returns>True if the FirmwareVersion is equal to this FirmwareVersion; False otherwise.</returns>
			virtual bool Equals(FirmwareVersion firmwareVersion)
			{
				return this->FirmwareVersionMajor.Equals(firmwareVersion.FirmwareVersionMajor)
					&& this->FirmwareVersionMinor.Equals(firmwareVersion.FirmwareVersionMinor)
					&& this->FirmwareVersionPatch.Equals(firmwareVersion.FirmwareVersionPatch)
					&& this->FirmwareVersionHardwareRev.Equals(firmwareVersion.FirmwareVersionHardwareRev);
			}

			/// <summary>
			/// Returns a String representing this FirmwareVersion instance.
			/// </summary>
			/// <returns>The string representation</returns>
			String^ ToString( ) override 
			{
				return String::Format("{0}.{1}.{2}.{3}",
					FirmwareVersionMajor,
					FirmwareVersionMinor,
					FirmwareVersionPatch,
					FirmwareVersionHardwareRev);
			}
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
		};
	}
}

