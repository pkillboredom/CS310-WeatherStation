#include "stdafx.h"
#include "Percentage.h"

namespace WeatherStation::Structs {
	struct _Percentage {
		short Value;
		_Percentage(short _value) {
			if (_value < 0 || _value > 100) {
				throw new std::out_of_range("The value must be between 0 and 100");
			}
			else Value = _value;
		}
	};
}

