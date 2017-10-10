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
		WeatherParam<std::string> Name;

		//Expressed in Celcius
		WeatherParam<float> Temperature;

		//Expressed in Celcius
		WeatherParam<float> FeelsLikeTemperature;

		//Expressed in KMpH
		WeatherParam<float> WindSpeed;

		//Expressed in enum WindDirections
		WeatherParam<WindDirections> WindDirection;
		WeatherFrame() : Name("Station Name"), Temperature("Temperature"),
			WindSpeed("Wind Speed"),WindDirection("Wind Direction") {}

		WeatherFrame(WeatherParam<std::string> _name, WeatherParam<float> _temperature, 
			WeatherParam<float> _windSpeed, WeatherParam<WindDirections> _windDirection) {
			Name = _name;
			Temperature = _temperature;
			WindSpeed = _windSpeed;
			WindDirection = _windDirection;
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
			Str << v.Name << "\n";
			Str << v.Temperature << " " << tempUnit << "\n";
			Str << v.WindSpeed << " " << windUnit << "\n";
			Str << "Wind Direction = ";
			//"temporary" workaround for enum issue.
			if(v.WindDirection.value >= 0 && v.WindDirection.value < 16){
				Str << windDirectionArr[v.WindDirection.value] << "\n";
			}
			else {
				Str << "Unavailiable\n";
			}

			return Str;
		}
	};
}