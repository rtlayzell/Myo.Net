#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

#include <myo/libmyo.h>
#include <vector>
#include "MyoEventArgs.hpp"
#include "RecognizedArmEventArgs.hpp"
#include "Myo.hpp"

namespace Thalmic
{
	namespace Myo
	{
		public ref class Hub
		{
		private:
			libmyo_hub_t _hub;
			System::Collections::Generic::List<IMyo^>^ _myos;


		internal:
			IMyo^ _AdoptMyo(libmyo_myo_t opaqueMyo);
			IMyo^ _FindMyo(libmyo_myo_t opaqueMyo);

			void _OnDeviceEvent(libmyo_event_t ev);
			libmyo_hub_t _libmyoObject( ) { return _hub; }

			property System::Collections::Generic::IList<IMyo^>^ Myos {
				System::Collections::Generic::IList<IMyo^>^ get( ) { return _myos; }
			}

		public:
			Hub( );
			Hub(String^ applicationIdentifier);
			~Hub( );

			IMyo^ WaitForMyo(TimeSpan timeout);
			System::Threading::Tasks::Task<IMyo^>^ WaitForMyoAsync(TimeSpan timeout); // not implemented.

			void Run(TimeSpan duration);
			void RunOnce(TimeSpan duration);
			System::Threading::Tasks::Task^ RunAsync(TimeSpan duration); // not implemented.
			System::Threading::Tasks::Task^ RunOnceAsync(TimeSpan duration); // not implemented.

			event EventHandler<MyoEventArgs^>^ MyoConnected;
			event EventHandler<MyoEventArgs^>^ MyoDisconnected;
			
			event EventHandler<MyoEventArgs^>^ MyoPaired;
			event EventHandler<MyoEventArgs^>^ MyoUnpaired;

			event EventHandler<RecognizedArmEventArgs^>^ RecognizedArm;
			event EventHandler<MyoEventArgs^>^ LostArm;
		};
	}
}

