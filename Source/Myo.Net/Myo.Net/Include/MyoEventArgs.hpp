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
			MyoEventArgs(IMyo^ myo, DateTimeOffset timeStamp)
				: _myo(myo), _timeStamp(timeStamp) { }
			 
			property IMyo^ Myo { IMyo^ get( ) { return this->_myo; } }
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

