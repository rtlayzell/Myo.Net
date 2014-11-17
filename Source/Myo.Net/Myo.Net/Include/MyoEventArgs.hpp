#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::Runtime::InteropServices;

namespace Thalmic
{
	namespace Myo
	{
		interface class IMyo;

		public ref class MyoEventArgs : public EventArgs
		{
		private:
			IMyo^ _myo;
			DateTimeOffset _timeStamp;

		public:
			///<summary>
			/// Initializes a new instance of <see cref="MyoEventArgs"/>.
			///</summary>
			MyoEventArgs(IMyo^ myo, DateTimeOffset timeStamp)
				: _myo(myo), _timeStamp(timeStamp) { }
			
			///<summary>
			/// Gets the <see cref="IMyo"/> associated with the event.
			///</summary>
			property IMyo^ Myo { IMyo^ get( ) { return this->_myo; } }

			///<summary>
			/// Gets the time stamp at which the event occurred.
			///</summary>
			property DateTimeOffset TimeStamp{ DateTimeOffset get( ) { return this->_timeStamp; } }
		};

		/*[SerializableAttribute]
		[System::Runtime::InteropServices::ComVisibleAttribute(true)]
		public delegate void MyoEventHandler(IMyo^ myo, MyoEventArgs^ e);

		generic <class TMyoEventArgs>
		[SerializableAttribute]
		public delegate void MyoEventHandler(IMyo^ myo, TMyoEventArgs^ e);*/
	}
}

