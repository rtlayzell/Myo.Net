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
		public enum class VibrationType
		{
			Short,
			Medium,
			Long,
		};

		/// Firmware version of Myo.
		public value struct FirmwareVersion 
		{
			unsigned int FirmwareVersionMajor; ///< Myo's major version must match the required major version.
			unsigned int FirmwareVersionMinor; ///< Myo's minor version must match the required minor version.
			unsigned int FirmwareVersionPatch; ///< Myo's patch version must greater or equal to the required patch version.
			unsigned int FirmwareVersionHardwareRev; ///< Myo's hardware revision; not used to detect firmware version mismatch.

			virtual String^ ToString( ) override {
				return String::Format("{0}.{1}.{2}.{3}",
					FirmwareVersionMajor,
					FirmwareVersionMinor,
					FirmwareVersionPatch,
					FirmwareVersionHardwareRev);
			}
		};

		public interface class IMyo : public IDisposable
		{
			event EventHandler<OrientationDataEventArgs^>^ OrientationDataAcquired;
			event EventHandler<AccelerometerDataEventArgs^>^ AccelerometerDataAcquired;
			event EventHandler<GyroscopeDataEventArgs^>^ GyroscopeDataAquired;
			event EventHandler<RssiDataEventArgs^>^ Rssi;
			event EventHandler<PoseEventArgs^>^ Pose;

			property String^ Name { String^ get( ); }
			property String^ MacAddress { String^ get( ); }

			property Thalmic::Myo::FirmwareVersion^ FirmwareVersion
			{ Thalmic::Myo::FirmwareVersion^ get( ); }

			void Vibrate(VibrationType type);
			void RequestRssi( );
		};

		private ref class Myo : public IMyo
		{
		private:
			libmyo_myo_t _myo;
			FirmwareVersion _firmware;

		internal:
			void _OnDeviceEvent(libmyo_event_t ev);
			void _SetFirmwareVersion(FirmwareVersion version);

			libmyo_myo_t _libmyoObject( ) { return _myo; }

		public:
			Myo(libmyo_myo_t opaque);
			~Myo( );

			virtual property String^ Name { String^ get( ) { return String::Empty; } }
			virtual property String^ MacAddress { String^ get( ) { return String::Empty; } }
			virtual property Thalmic::Myo::FirmwareVersion^ FirmwareVersion { Thalmic::Myo::FirmwareVersion^ get( ) { return _firmware; } }

			virtual event EventHandler<OrientationDataEventArgs^>^ OrientationDataAcquired;
			virtual event EventHandler<AccelerometerDataEventArgs^>^ AccelerometerDataAcquired;
			virtual event EventHandler<GyroscopeDataEventArgs^>^ GyroscopeDataAquired;
			virtual event EventHandler<RssiDataEventArgs^>^ Rssi;
			virtual event EventHandler<PoseEventArgs^>^ Pose;

			virtual void Vibrate(VibrationType type);
			virtual void RequestRssi( );
		};
	}
}

