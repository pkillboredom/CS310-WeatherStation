//Author Luke Tomkus

#pragma once
#include "WeatherFrame.h"

namespace WeatherStation::Structs {
	template <typename t>
	struct inputValidatorResponse {
		bool isQuit;
		int isValid;
		WeatherStation::Structs::WeatherParam<t> value;
		//Default Constructor sets as not quitting, but invalid param.
		inputValidatorResponse() : isQuit(false), isValid(0) {}
		//Takes one bool setting isQuit, isValid set to false.
		inputValidatorResponse(bool _isQuit) : isQuit(_isQuit), isValid(0) {}
		//Takes a bool for isQuit, and a bool for isValid.
		inputValidatorResponse(bool _isQuit, int _isValid) : isQuit(_isQuit), isValid(_isValid) {}
		//Takes bool for isQuit, bool for isValid, and t for Value.
		inputValidatorResponse(bool _isQuit, int _isValid, WeatherStation::Structs::WeatherParam<t> _value) : isQuit(_isQuit), isValid(_isValid), value(_value) {}
	};
}