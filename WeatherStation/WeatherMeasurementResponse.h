//Author Luke Tomkus

#pragma once
#include "WeatherMeasurement.h"

namespace WeatherStation::Structs {

	typedef struct WeatherMeasurementResponse {
		bool isQuit;
		bool isDeny;
		WeatherMeasurement weatherMeasurement;
		//Default sets isQuit false.
		WeatherMeasurementResponse() : isQuit(false) {}
		//Takes bool for isQuit and isDeny
		WeatherMeasurementResponse(bool _isQuit, bool _isDeny) : isQuit(_isQuit), isDeny(_isDeny) {}
		//Takes WeatherMeasurement for WeatherMeasurement
		WeatherMeasurementResponse(WeatherMeasurement _WeatherMeasurement) : isQuit(false), weatherMeasurement(_WeatherMeasurement) {}
	};
}