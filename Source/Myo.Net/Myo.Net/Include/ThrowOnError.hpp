
#include <stdexcept>

#include <myo/libmyo.h>


namespace Thalmic
{
	namespace Myo
	{
		private ref class ThrowHelper abstract sealed
		{
		public:
			static void ThrowOnError(libmyo_error_details_t err);
		};
	}
}
