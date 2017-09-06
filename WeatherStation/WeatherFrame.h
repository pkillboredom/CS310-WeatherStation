#pragma once

#include "Percentage.h"

namespace WeatherStation::Structs {
	typedef struct WeatherFrame
	{
		//Expressed in Celcius
		WeatherParam<float> *Temperature;
		//Expressed in Celcius
		WeatherParam<float> *FeelsLikeTemperature;
		//Expressed in Celcius
		WeatherParam<float> *HeatIndex;
		//Expressed in Celcius
		WeatherParam<float> *DewPoint;


		//Expressed in KMpH
		WeatherParam<float> *WindSpeed;

		//Expressed in KMpH
		WeatherParam<float> *WindGust;

		//Expressed in enum WindDirections
		WeatherParam<WindDirections> *WindDirection;

		//Expressed in KM
		WeatherParam<float> *Visibility;

		//Expressed in percents
		WeatherParam<Percentage> *Humidity;

		//Expressed in hPa
		WeatherParam<unsigned int> *Pressure;

		WeatherFrame() : Temperature(), FeelsLikeTemperature(), HeatIndex(), DewPoint(),
			WindSpeed(), WindGust(), WindDirection(), Visibility(), Pressure() {}

		WeatherFrame(float _temperature, float _feelsLikeTemperature, float _heatIndex, float _dewPoint,
			float _windSpeed, float _windGust, WindDirections _windDirection, float _visibiity,
			Percentage _humidity, unsigned int _pressure) {
			Temperature = new WeatherParam<float>(_temperature);
			FeelsLikeTemperature = new WeatherParam<float>(_feelsLikeTemperature);
			HeatIndex = new WeatherParam<float>(_heatIndex);
			DewPoint = new WeatherParam<float>(_dewPoint);
			WindSpeed = new WeatherParam<float>(_windSpeed);
			WindGust = new WeatherParam<float>(_windGust);
			WindDirection = new WeatherParam<WindDirections>(_windDirection);
			Visibility = new WeatherParam<float>(_visibiity);
			Humidity = new WeatherParam<Percentage>(_humidity);
			Pressure = new WeatherParam<unsigned int>(_pressure);
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

	template <typename t>
	typedef struct WeatherParam {
		t value;
		bool isAvailiable;
		WeatherParam() {
			isAvailiable = false;
		}
		WeatherParam(t _value) {
			value = _value;
			isAvailiable = true;
		}
		WeatherParam(t _value, bool _isAvailiable) {
			value = _value;
			isAvailiable = _isAvailiable;
		}
	};
}