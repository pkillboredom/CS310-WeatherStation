#pragma once
//I already made a templated WeatherParam with input validation, etc.
//See Wind.h and WeatherMeasurement.h
//Defines below used in WeatherMeasurement.h
#define WindDirection WeatherParam<WindDirections>
#define WindSpeed WeatherParam<float>