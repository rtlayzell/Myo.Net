#include "Stdafx.h"
#include "Myo.hpp"
#include "ThrowOnError.hpp"


namespace Thalmic
{
	namespace Myo
	{
		Myo::Myo(libmyo_myo_t opaque)
			: _myo(opaque)
		{
			if (!opaque)
				throw gcnew ArgumentException(
				"Cannot construct Myo instance with null pointer.");
		}
		
		Myo::~Myo() { }

		void Myo::_SetFirmwareVersion(Thalmic::Myo::FirmwareVersion version)
		{
			_firmware = version;
		}

		void Myo::_OnDeviceEvent(libmyo_event_t ev)
		{
			DateTimeOffset dtime = DateTimeOffset::Now;

			switch (libmyo_event_get_type(ev))
			{
			case libmyo_event_orientation:
				this->OrientationDataAcquired(this,
					gcnew OrientationDataEventArgs(this, dtime, Quaternion(
					libmyo_event_get_orientation(ev, libmyo_orientation_x),
					libmyo_event_get_orientation(ev, libmyo_orientation_y),
					libmyo_event_get_orientation(ev, libmyo_orientation_z),
					libmyo_event_get_orientation(ev, libmyo_orientation_w))));
			
				this->AccelerometerDataAcquired(this, 
					gcnew AccelerometerDataEventArgs(this, dtime, Vector3(
					libmyo_event_get_accelerometer(ev, 0),
					libmyo_event_get_accelerometer(ev, 1),
					libmyo_event_get_accelerometer(ev, 2))));

				this->GyroscopeDataAquired(this,
					gcnew GyroscopeDataEventArgs(this, dtime, Vector3(
					libmyo_event_get_gyroscope(ev, 0),
					libmyo_event_get_gyroscope(ev, 1),
					libmyo_event_get_gyroscope(ev, 2))));

				break;
			case libmyo_event_pose:
				this->Pose(this, gcnew PoseEventArgs(this, dtime,
					Thalmic::Myo::Pose(static_cast<Thalmic::Myo::Pose>(libmyo_event_get_pose(ev)))));
				break;
			case libmyo_event_rssi:
				this->Rssi(this, gcnew RssiDataEventArgs(this, dtime, libmyo_event_get_rssi(ev)));
				break;
			}
		}

		void Myo::Vibrate(VibrationType type)
		{
			libmyo_error_details_t err = 0;
			libmyo_vibrate(_myo, static_cast<libmyo_vibration_type_t>(type), &err);
			ThrowHelper::ThrowOnError(err);
		}

		void Myo::RequestRssi( )
		{
			libmyo_error_details_t err = 0;
			libmyo_request_rssi(_myo, &err);
			ThrowHelper::ThrowOnError(err);
		}
	}
}