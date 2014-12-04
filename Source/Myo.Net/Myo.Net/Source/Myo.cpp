#include "Stdafx.h"
#include "Myo.hpp"
#include "ThrowOnError.hpp"


namespace MyoNet
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

		void Myo::_SetFirmwareVersion(MyoNet::Myo::FirmwareVersion version)
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
				this->PoseChanged(this, gcnew PoseChangedEventArgs(this, dtime,
					MyoNet::Myo::Pose(static_cast<MyoNet::Myo::Pose>(libmyo_event_get_pose(ev)))));
				break;

			case libmyo_event_rssi:
				this->Rssi(this, gcnew RssiDataEventArgs(this, dtime, libmyo_event_get_rssi(ev)));
				break;

			case libmyo_event_arm_synced:
				this->RecognizedArm(this, gcnew RecognizedArmEventArgs(this, dtime, 
					static_cast<Arm>(libmyo_event_get_arm(ev)),
					static_cast<XDirection>(libmyo_event_get_x_direction(ev))));
				break;

			case libmyo_event_arm_unsynced:
				this->LostArm(this, gcnew MyoEventArgs(this, dtime));
				break;

			case libmyo_event_unlocked:
				this->Unlocked(this, gcnew MyoEventArgs(this, dtime));
				break;

			case libmyo_event_locked:
				this->Locked(this, gcnew MyoEventArgs(this, dtime));
				break;
			}
		}

		void Myo::Vibrate(VibrationType type)
		{
			libmyo_error_details_t err = 0;
			libmyo_vibrate(_myo, static_cast<libmyo_vibration_type_t>(type), &err);
			ThrowHelper::ThrowOnError(err);

			libmyo
		}

		void Myo::RequestRssi( )
		{
			libmyo_error_details_t err = 0;
			libmyo_request_rssi(_myo, &err);
			ThrowHelper::ThrowOnError(err);
		}

		void Myo::Unlock(UnlockType type)
		{
			libmyo_error_details_t err = 0;
			libmyo_myo_unlock(_myo, static_cast<libmyo_unlock_type_t>(type), &err);
			ThrowHelper::ThrowOnError(err);
		}

		void Myo::Lock( )
		{
			libmyo_error_details_t err = 0;
			libmyo_myo_lock(_myo, &err);
			ThrowHelper::ThrowOnError(err);
		}

		void Myo::NotifyUserAction( )
		{
			libmyo_error_details_t err = 0;
			libmyo_myo_notify_user_action(_myo, libmyo_user_action_single, &err);
			ThrowHelper::ThrowOnError(err);
		}
	}
}