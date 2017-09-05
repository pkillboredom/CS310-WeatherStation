#pragma once

#include "Percentage.h"

namespace WeatherStation::Structs {
	typedef struct WeatherFrame
	{
		//Expressed in Celcius
		float Temperature;
		//Expressed in Celcius
		float FeelsLikeTemperature;
		//Expressed in Celcius
		float HeatIndex;
		//Expressed in Celcius
		float DewPoint;


		//Expressed in KMpH
		float WindSpeed;
		//Expressed in KMpH
		float WindGust;

		//Expressed in enum WindDirections
		WindDirections WindDirection;

		//Expressed in KM
		float Visibility;

		//Expressed in percents
		Percentage Humidity;

		//Expressed in hPa
		unsigned int Pressure;

		WeatherFrame() : Temperature(0.0), FeelsLikeTemperature(0.0), HeatIndex(0.0), DewPoint(0.0),
			WindSpeed(0.0), WindGust(0.0), WindDirection(N), Visibility(0.0), Pressure(0.0) {}

		WeatherFrame(float _temperature, float _feelsLikeTemperature, float _heatIndex, float _dewPoint,
			float _windSpeed, float _windGust, WindDirections _windDirection, float _visibiity,
			Percentage _humidity, unsigned int _pressure) {
			Temperature = _temperature;
			FeelsLikeTemperature = _feelsLikeTemperature;
			HeatIndex = _heatIndex;
			DewPoint = _dewPoint;
			WindSpeed = _windSpeed;
			WindGust = _windGust;
			WindDirection = _windDirection;
			Visibility = _visibiity;
			Humidity = _humidity;
			Pressure = _pressure;
		}
	};

	typedef enum WindDirections {
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