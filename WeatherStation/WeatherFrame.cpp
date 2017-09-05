#include "stdafx.h"
#include "Percentage.h"

namespace WeatherStation::Structs {
	struct WeatherFrame
	{
		//Expressed in Celcius
		float Temperature;
		float FeelsLikeTemperature;
		float HeatIndex;
		float DewPoint;
		//Expressed in KMpH
		float WindSpeed;
		float WindGust;
		WindDirections WindDirection;
		//Expressed in KM
		float Visibility;
		//Expressed in percents
		Percentage Humidity;
	};
	
	enum WindDirections {
		N,
		NNE,
		NE,
		ENE,
		E,
		ESE,
		SE,
		SSE,
		S,
		SSW,
		SW,
		WSW,
		W,
		WNW,
		NW,
		NNW
	};
}