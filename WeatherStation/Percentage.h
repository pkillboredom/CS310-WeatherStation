//Author Luke Tomkus

#pragma once
namespace WeatherStation::Structs {
	typedef struct Percentage {
		int Value;
		Percentage() : Value(0.0) {}
		Percentage(int _value) {
			if (_value < 0 || _value > 100) {
				throw new std::out_of_range("The value must be between 0 and 100");
			}
			else Value = _value;
		}
		friend std::ostream & operator<<(std::ostream & Str, Percentage& v) {
			Str << "" << v.Value << "%";
			return Str;
		}
	};
}