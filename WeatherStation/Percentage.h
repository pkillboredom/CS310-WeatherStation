#pragma once
namespace WeatherStation::Structs {
	typedef struct Percentage {
		short Value;
		Percentage() : Value(0.0) {}
		Percentage(short _value) {
			if (_value < 0 || _value > 100) {
				throw new std::out_of_range("The value must be between 0 and 100");
			}
			else Value = _value;
		}
	};
}