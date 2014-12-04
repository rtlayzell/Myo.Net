#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

#include "MyoEventArgs.hpp"
#include "RecognizedArmEventArgs.hpp"
#include "IMyo.hpp"

namespace MyoNet
{
	namespace Myo
	{
		public enum class LockingPolicy
		{
			None = libmyo_locking_policy_none,
			Standard = libmyo_locking_policy_standard,
		};

		/// <summary>A Hub provides access to one or more Myo instances.</summary>
		public interface class IHub
		{
			/// <summary>
			/// Gets or sets the locking policy for Myos connected to the Hub.
			/// </summary>
			property LockingPolicy LockingPolicy 
			{ 
				::MyoNet::Myo::LockingPolicy get();
				void set(::MyoNet::Myo::LockingPolicy);
			}
		
			/// <summary>
			/// Wait for a Myo to become paired.
			/// </summary>
			IMyo^ WaitForMyo( );

			/// <summary>
			/// Wait for a Myo to become paired, or time out after <paramref name="timeout"/>. 
			/// </summary>
			/// <param name="timeout">The amount of time to wait until time out occurs.</param>
			IMyo^ WaitForMyo(TimeSpan timeout);

#if defined NETFX_40
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			System::Threading::Tasks::Task<IMyo^>^ WaitForMyoAsync(TimeSpan timeout); // not implemented.
#endif

			/// <summary>
			/// Run the event loop.
			/// </summary>
			void Run( );

			/// <summary>
			/// Run the event loop until a single event occurs. 
			/// </summary>
			void RunOnce( );

			/// <summary>
			/// Run the event loop for the specified <paramref name="duration" />. 
			/// </summary>
			/// <param name="duration">The amount of time to run the event loop.</param>
			void Run(TimeSpan duration);

			/// <summary>
			/// Run the event loop until a single event occurs, or the specified <paramref name="duration"/> has elapsed. 
			/// </summary>
			/// <param name="duration">The amount of time to run the event loop.</param>
			void RunOnce(TimeSpan duration);
	
#if defined NETFX_40
			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			System::Threading::Tasks::Task^ RunAsync(TimeSpan duration); // not implemented.

			[System::ComponentModel::EditorBrowsableAttribute(System::ComponentModel::EditorBrowsableState::Never)]
			System::Threading::Tasks::Task^ RunOnceAsync(TimeSpan duration); // not implemented.
#endif
			/// <summary>
			/// Occurs when a paired Myo has been connected. 
			/// </summary>
			event EventHandler<MyoEventArgs^>^ MyoConnected;

			/// <summary>
			/// Occurs when a paired Myo has been disconnected. 
			/// </summary>
			event EventHandler<MyoEventArgs^>^ MyoDisconnected;
			
			/// <summary>
			/// Occurs when a Myo has been paired. 
			/// </summary>
			event EventHandler<MyoEventArgs^>^ MyoPaired;

			/// <summary>
			/// Occurs when a Myo has been unpaired. 
			/// </summary>
			event EventHandler<MyoEventArgs^>^ MyoUnpaired;
		};
	}
}

