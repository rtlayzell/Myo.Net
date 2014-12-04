#pragma once

using namespace System;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

#include "HashCodeHelper.hpp"

namespace MyoNet
{
	namespace Myo
	{

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
	}
}