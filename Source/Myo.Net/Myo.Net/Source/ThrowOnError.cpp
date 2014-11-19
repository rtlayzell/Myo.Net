#include "stdafx.h"
#include "ThrowOnError.hpp"

#include <msclr\marshal_cppstd.h>


namespace MyoNet
{
	namespace Myo
	{
		void ThrowHelper::ThrowOnError(libmyo_error_details_t err)
		{
			if (err)
			{
				System::Exception^ exception = nullptr;
				switch (libmyo_error_kind(err))
				{
				case libmyo_error:
				case libmyo_error_runtime:
					exception = gcnew System::InvalidOperationException(
						msclr::interop::marshal_as<System::String^>(libmyo_error_cstring(err)));
					libmyo_free_error_details(err);
					throw exception;

				case libmyo_error_invalid_argument:
					exception = gcnew System::ArgumentException(
						msclr::interop::marshal_as<System::String^>(libmyo_error_cstring(err)));
					libmyo_free_error_details(err);
					throw exception;

				case libmyo_success:
					break;
				}
			}
		}
	}
}
