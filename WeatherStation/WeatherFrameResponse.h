//Author Luke Tomkus

#pragma once
#include "WeatherFrame.h"

namespace WeatherStation::Structs {

	typedef struct WeatherFrameResponse {
		bool isQuit;
		bool isDeny;
		WeatherFrame weatherFrame;
		//Default sets isQuit false.
		WeatherFrameResponse() : isQuit(false) {}
		//Takes bool for isQuit and isDeny
		WeatherFrameResponse(bool _isQuit, bool _isDeny) : isQuit(_isQuit), isDeny(_isDeny) {}
		//Takes WeatherFrame for weatherFrame
		WeatherFrameResponse(WeatherFrame _weatherFrame) : isQuit(false), weatherFrame(_weatherFrame) {}
	};
}