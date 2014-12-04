#include "Stdafx.h"
#include <msclr\marshal_cppstd.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "Hub.hpp"
#include "ThrowOnError.hpp"
#include "FirmwareVersion.hpp"

namespace MyoNet
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

		::MyoNet::Myo::LockingPolicy Hub::LockingPolicy::get( )
		{
			return _lockPolicy;
		}

		void Hub::LockingPolicy::set(::MyoNet::Myo::LockingPolicy value)
		{
			libmyo_error_details_t err;
			libmyo_set_locking_policy(_hub, 
				static_cast<libmyo_locking_policy_t>(value), &err);
			ThrowHelper::ThrowOnError(err);
			_lockPolicy = value;
		}


		Hub::Hub() : Hub("") { }
		
		Hub::Hub(String^ applicationIdentifier) :_hub(0), _myos(nullptr) 
		{
			cli::pin_ptr<libmyo_hub_t> pinned_hub = &_hub;

			libmyo_error_details_t err = 0;
			libmyo_init_hub(pinned_hub, msclr::interop::marshal_as<std::string>(applicationIdentifier).c_str(), &err);
			ThrowHelper::ThrowOnError(err);
			
			_myos = gcnew System::Collections::Generic::List<IMyo^>( );
		}

		Hub::~Hub( ) 
		{
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

			//uint64_t time = libmyo_event_get_timestamp(ev);

			// The libmyo SDK produces a timestamp without any known point of origin.
			// This to me, and probably others, is useless without some calibration
			// on the part of the user.  Instead of the libmyo timestamp a DateTimeOffset
			// is retrieved here and used in its place.
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
			}

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
			} finally { hub_handle.Free( ); }
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
			} finally { hub_handle.Free( ); }
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

#if defined NETFX_40

		ref class WaitForMyoAsyncHelper
		{
		private:
			Hub^ _object;
			TimeSpan _timeSpan;

			WaitForMyoAsyncHelper(Hub^ object, TimeSpan timeSpan)
				: _object(object), _timeSpan(timeSpan) { }

			IMyo^ Execute( ) { return _object->WaitForMyo(_timeSpan); }

		public:
			static System::Func<IMyo^>^ Create(Hub^ object, TimeSpan timeSpan)
			{
				return gcnew Func<IMyo^>(
					gcnew WaitForMyoAsyncHelper(object, timeSpan), 
					&WaitForMyoAsyncHelper::Execute);
			}
		};

		System::Threading::Tasks::Task<IMyo^>^ Hub::WaitForMyoAsync(TimeSpan timeout)
		{
			return System::Threading::Tasks::Task<IMyo^>::Factory->StartNew(
				WaitForMyoAsyncHelper::Create(this, timeout),
				System::Threading::CancellationToken::None,
				System::Threading::Tasks::TaskCreationOptions::None,
				System::Threading::Tasks::TaskScheduler::Default);
		}
#endif

		void Hub::Run( )
		{
			run_impl(this, 0);
		}

		void Hub::RunOnce( )
		{
			run_once_impl(this, 0);
			#if defined NETFX_40
			#endif
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



#if defined NETFX_40

		ref class RunAsyncHelper
		{
		private:
			Hub^ _object;
			TimeSpan _duration;

			RunAsyncHelper(Hub^ object, TimeSpan duration)
				: _object(object), _duration(duration) { }

			void Execute( ) { return _object->Run(_duration); }

		public:
			static System::Action^ Create(Hub^ object, TimeSpan duration)
			{
				return gcnew Action(
					gcnew RunAsyncHelper(object, duration), 
					&RunAsyncHelper::Execute);
			}
		};

		// something needs to be done about this bloat.... damn lambdas so useful..
		ref class RunOnceAsyncHelper
		{
		private:
			Hub^ _object;
			TimeSpan _duration;

			RunOnceAsyncHelper(Hub^ object, TimeSpan duration)
				: _object(object), _duration(duration) { }

			void Execute( ) { return _object->RunOnce(_duration); }

		public:
			static System::Action^ Create(Hub^ object, TimeSpan duration)
			{
				return gcnew Action(
					gcnew RunOnceAsyncHelper(object, duration), 
					&RunOnceAsyncHelper::Execute);
			}
		};

		System::Threading::Tasks::Task^ Hub::RunAsync(TimeSpan duration)
		{
			return System::Threading::Tasks::Task::Factory->StartNew(
				RunAsyncHelper::Create(this, duration),
				System::Threading::CancellationToken::None,
				System::Threading::Tasks::TaskCreationOptions::None,
				System::Threading::Tasks::TaskScheduler::Default);
		}

		System::Threading::Tasks::Task^ Hub::RunOnceAsync(TimeSpan duration) 
		{
			return System::Threading::Tasks::Task::Factory->StartNew(
				RunOnceAsyncHelper::Create(this, duration),
				System::Threading::CancellationToken::None,
				System::Threading::Tasks::TaskCreationOptions::None,
				System::Threading::Tasks::TaskScheduler::Default);
		}
#endif
	}
}

