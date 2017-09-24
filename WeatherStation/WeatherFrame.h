//Author Luke Tomkus

#pragma once

#include "stdafx.h"
#include "Percentage.h"
#include "WindDirections.h"

namespace WeatherStation::Structs {

	template <typename t>
	struct WeatherParam {
		t value;
		bool isAvailiable;
		std::string name;
		WeatherParam() {
			name = "Unnamed";
			isAvailiable = false;
		}
		WeatherParam(std::string _name) {
			name = _name;
			isAvailiable = false;
		}
		WeatherParam(t _value, std::string _name) {
			value = _value;
			isAvailiable = true;
			name = _name;
		}
		WeatherParam(t _value, bool _isAvailiable, std::string _name) {
			value = _value;
			isAvailiable = _isAvailiable;
			name = _name;
		}
		friend std::ostream & operator<<(std::ostream & Str, WeatherParam& v) {
			if (v.isAvailiable) {
				Str << v.name << " = " << v.value;
			}
			else {
				Str << v.name << " = Unavailiable.";
			}
			return Str;
		}
	};

	typedef struct WeatherFrame
	{
		//Expressed in Celcius
		WeatherParam<float> Temperature;
		//Expressed in Celcius
		WeatherParam<float> FeelsLikeTemperature;
		//Expressed in Celcius
		WeatherParam<float> HeatIndex;
		//Expressed in Celcius
		WeatherParam<float> DewPoint;


		//Expressed in KMpH
		WeatherParam<float> WindSpeed;

		//Expressed in KMpH
		WeatherParam<float> WindGust;

		//Expressed in enum WindDirections
		WeatherParam<WindDirections> WindDirection;

		//Expressed in KM
		WeatherParam<float> Visibility;

		//Expressed in percents
		WeatherParam<Percentage> Humidity;

		//Expressed in hPa
		WeatherParam<int> Pressure;


		WeatherFrame() : Temperature("Temperature"), FeelsLikeTemperature("Feels Like Temperature"), HeatIndex("Heat Index"), DewPoint("Dew Point"),
			WindSpeed("Wind Speed"), WindGust("Wind Gust"), WindDirection("Wind Direction"), Visibility("Visibility"), Humidity("Humidity"), Pressure("Pressure") {}

		WeatherFrame(WeatherParam<float> _temperature, WeatherParam<float> _feelsLikeTemperature, WeatherParam<float> _heatIndex, WeatherParam<float> _dewPoint,
			WeatherParam<float> _windSpeed, WeatherParam<float> _windGust, WeatherParam<WindDirections> _windDirection, WeatherParam<float> _visibiity,
			WeatherParam<Percentage> _humidity, WeatherParam<int> _pressure) {
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
		friend std::ostream & operator<<(std::ostream & Str, WeatherFrame& v) {

			//This array is a temporary measure for outputting the name corresponding to the wind dir enum
			//Temporary...
			std::string windDirectionArr[] = { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };

			//Strings for the unit displays. Eventually these will be governed by options.
			std::string tempUnit = "deg C";
			std::string windUnit = "KMpH";
			std::string distUnit = "KM";
			std::string pressUnit = "hPa";

			Str << "This frame of Weather Data:" << std::endl;
			Str << v.Temperature << " " << tempUnit << "\n";
			Str << v.FeelsLikeTemperature << " " << tempUnit << "\n";
			Str << v.HeatIndex << " " << tempUnit << "\n";
			Str << v.DewPoint << " " << tempUnit << "\n";
			Str << v.WindSpeed << " " << windUnit << "\n";
			Str << v.WindGust << " " << windUnit << "\n";
			Str << "Wind Direction = " << windDirectionArr[v.WindDirection.value] << "\n";
			Str << v.Visibility << " " << distUnit << "\n";
			Str << v.Humidity << "\n";
			Str << v.Pressure << " " << pressUnit << "\n";

			return Str;
		}
	};
}