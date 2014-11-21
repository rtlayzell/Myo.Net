#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;


namespace MyoNet
{
	namespace Myo
	{
		private ref class HashCodeHelper abstract sealed
		{
		public:
			/// <summary> 
			/// Combines two hash codes, useful for combining hash codes of individual vector elements 
			/// </summary> 
			static int CombineHashCodes(int lhs, int rhs);
		};
	}
}

