#include "Stdafx.h"
#include <msclr\marshal_cppstd.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "Hub.hpp"
#include "ThrowOnError.hpp"

namespace Thalmic
{
	namespace Myo
	{
		FirmwareVersion _ConstructFirmwareVersion(libmyo_event_t ev)
		{
			FirmwareVersion version = FirmwareVersion(
				libmyo_event_get_firmware_version(ev, libmyo_version_major), 
				libmyo_event_get_firmware_version(ev, libmyo_version_minor), 
				libmyo_event_get_firmware_version(ev, libmyo_version_patch), 
				libmyo_event_get_firmware_version(ev, libmyo_version_hardware_rev));

			return version;
		}

		Hub::Hub() : Hub("") { 
		}
		
		Hub::Hub(String^ applicationIdentifier) :_hub(0), _myos(nullptr) {
			cli::pin_ptr<libmyo_hub_t> pinned_hub = &_hub;

			libmyo_error_details_t err = 0;
			libmyo_init_hub(pinned_hub, msclr::interop::marshal_as<std::string>(applicationIdentifier).c_str(), &err);
			ThrowHelper::ThrowOnError(err);
			
			_myos = gcnew System::Collections::Generic::List<IMyo^>( );
		}

		Hub::~Hub( ) {
			libmyo_error_details_t err = 0;
			libmyo_shutdown_hub(_hub, &err);
			ThrowHelper::ThrowOnError(err);
		}

		IMyo^ Hub::_AdoptMyo(libmyo_myo_t opaqueMyo)
		{
			IMyo^ myo = gcnew Myo(opaqueMyo);
			_myos->Add(myo);

			return myo;
		}

		IMyo^ Hub::_FindMyo(libmyo_myo_t opaqueMyo)
		{
			IMyo^ result = nullptr;
			for each (IMyo^ myo in this->_myos)
			{
				if (((Myo^)myo)->_libmyoObject( ) == opaqueMyo)
				{
					result = myo;
					break;
				}
			}

			return result;
		}

		void Hub::_OnDeviceEvent(libmyo_event_t ev)
		{
			libmyo_myo_t opaqueMyo = libmyo_event_get_myo(ev);
			IMyo^ myo = _FindMyo(opaqueMyo);

			if (!myo && libmyo_event_get_type(ev) == libmyo_event_paired)
				myo = _AdoptMyo(opaqueMyo);

			if (!myo)
			{
				// Ignore events for Myos we don't know about.
				return;
			}

			uint64_t time = libmyo_event_get_timestamp(ev);
			DateTimeOffset dtime = DateTimeOffset::Now;

			switch (libmyo_event_get_type(ev))
			{
			case libmyo_event_paired:
				((Myo^)myo)->_SetFirmwareVersion(_ConstructFirmwareVersion(ev));
				this->MyoPaired(this, gcnew MyoEventArgs(myo, dtime));
				break;

			case libmyo_event_unpaired:
				this->MyoUnpaired(this, gcnew MyoEventArgs(myo, dtime));
				break;

			case libmyo_event_connected:
				((Myo^)myo)->_SetFirmwareVersion(_ConstructFirmwareVersion(ev));
				this->MyoConnected(this, gcnew MyoEventArgs(myo, dtime));
				break;

			case libmyo_event_disconnected:
				this->MyoDisconnected(this, gcnew MyoEventArgs(myo, dtime));
				break;

			case libmyo_event_arm_synced:
				this->RecognizedArm(this, gcnew RecognizedArmEventArgs(myo, dtime, 
					static_cast<Arm>(libmyo_event_get_arm(ev)),
					static_cast<XDirection>(libmyo_event_get_x_direction(ev))));
				break;

			case libmyo_event_arm_unsynced:
				this->LostArm(this, gcnew MyoEventArgs(myo, dtime));
				break;
			}

			// could include a "handled" event mechanism here to stop the Myo device from recieving events.
			((Myo^)myo)->_OnDeviceEvent(ev);
		}

		void run_impl(Hub^ _hub, unsigned int duration_ms)
		{
			struct local {
				static libmyo_handler_result_t handler(void* user_data, libmyo_event_t event) {
					GCHandle handle = GCHandle::FromIntPtr(IntPtr(user_data));
					Hub^ hub = (Hub^)handle.Target;

					hub->_OnDeviceEvent(event);

					return libmyo_handler_continue;
				}
			};
			GCHandle hub_handle = GCHandle::Alloc(_hub);
			IntPtr pointer = GCHandle::ToIntPtr(hub_handle);

			try
			{
				libmyo_error_details_t err = 0;
				libmyo_run(_hub->_libmyoObject(), duration_ms, &local::handler, pointer.ToPointer(), &err);
				ThrowHelper::ThrowOnError(err);
			}
			finally { hub_handle.Free( ); }
		}

		void run_once_impl(Hub^ _hub, unsigned int duration_ms)
		{
			struct local
			{
				static libmyo_handler_result_t handler(void* user_data, libmyo_event_t event) {
					GCHandle handle = GCHandle::FromIntPtr(IntPtr(user_data));
					Hub^ hub = (Hub^)handle.Target;

					hub->_OnDeviceEvent(event);

					return libmyo_handler_stop;
				}
			};

			GCHandle hub_handle = GCHandle::Alloc(_hub);
			IntPtr pointer = GCHandle::ToIntPtr(hub_handle);

			try
			{
				libmyo_error_details_t err = 0;
				libmyo_run(_hub->_libmyoObject( ), duration_ms, &local::handler, pointer.ToPointer( ), &err);
				ThrowHelper::ThrowOnError(err);
			}
			finally { hub_handle.Free( ); }
		}

		IMyo^ wait_for_myo_impl(Hub^ _hub, unsigned int timeout_ms)
		{
			int prevSize = _hub->Myos->Count;

			struct local {
				static libmyo_handler_result_t handler(void* user_data, libmyo_event_t event) {
					GCHandle handle = GCHandle::FromIntPtr(IntPtr(user_data));
					Hub^ hub = (Hub^)handle.Target;

					libmyo_myo_t opaque_myo = libmyo_event_get_myo(event);

					switch (libmyo_event_get_type(event)) {
					case libmyo_event_paired:
						((Myo^)hub->_AdoptMyo(opaque_myo))
							->_SetFirmwareVersion(_ConstructFirmwareVersion(event));
						return libmyo_handler_stop;

					default:
						break;
					}

					return libmyo_handler_continue;
				}
			};


			GCHandle hub_handle = GCHandle::Alloc(_hub);
			IntPtr pointer = GCHandle::ToIntPtr(hub_handle);

			try
			{
				do
				{
					libmyo_error_details_t err = 0;
					libmyo_run(_hub->_libmyoObject( ), timeout_ms?timeout_ms:1000, &local::handler, pointer.ToPointer( ), &err);
					ThrowHelper::ThrowOnError(err);
				}
				while (!timeout_ms && _hub->Myos->Count <= prevSize);

				if (_hub->Myos->Count <= prevSize)
					return nullptr;

				return _hub->Myos[_hub->Myos->Count - 1];
			}
			finally { hub_handle.Free( ); }
		}

		IMyo^ Hub::WaitForMyo( )
		{
			return wait_for_myo_impl(this, 0);
		}

		IMyo^ Hub::WaitForMyo(TimeSpan timeout)
		{
			if ((unsigned int)timeout.TotalMilliseconds == 0) return nullptr; // throw here instead.
			return wait_for_myo_impl(this, (unsigned int)timeout.TotalMilliseconds);
		}

		System::Threading::Tasks::Task<IMyo^>^ Hub::WaitForMyoAsync(TimeSpan timeout){
			throw gcnew NotImplementedException( );
		}

		void Hub::Run( )
		{
			run_impl(this, 0);
		}

		void Hub::RunOnce( )
		{
			run_once_impl(this, 0);
		}

		void Hub::Run(TimeSpan duration)
		{
			if ((unsigned int)duration.TotalMilliseconds == 0) return; // throw here instead.
			run_impl(this, (unsigned int)duration.TotalMilliseconds);
		}

		void Hub::RunOnce(TimeSpan duration)
		{
			if ((unsigned int)duration.TotalMilliseconds == 0) return; // throw here instead.
			run_once_impl(this, (unsigned int)duration.TotalMilliseconds);
		}

		System::Threading::Tasks::Task^ Hub::RunAsync(TimeSpan duration) {
			throw gcnew NotImplementedException( );
		}

		System::Threading::Tasks::Task^ Hub::RunOnceAsync(TimeSpan duration) {
			throw gcnew NotImplementedException( );
		}
	}
}

