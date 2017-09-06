#include "stdafx.h"
#include <string>

using namespace WeatherStation::Structs;
using namespace std;

static WeatherStation::Structs::WeatherFrame InputPrompt() {

	///take in strings so that the professor cant throw exceptions on bad inputs
	string s_temperature;
	string s_feelsLikeTemperature;
	string s_heatIndex;
	string s_dewPoint;
	string s_windSpeed;
	string s_windDirection;
	string s_visibiity;
	string s_humidity;
	string s_pressure;

	///input handlers convert to correct types
	WeatherParam<float> *f_temperature;
	WeatherParam<float> *f_feelsLikeTemperature;
	WeatherParam<float> *f_heatIndex;
	WeatherParam<float> *f_dewPoint;
	WeatherParam<float> *f_windSpeed;
	WeatherParam<float> *f_windGust;
	WeatherParam<WindDirections> *f_windDirection;
	WeatherParam<float> *f_visibility;
	WeatherParam<Percentage> *f_humidity;
	WeatherParam<unsigned int> *Pressure;

	cout << "\nManual Weather Frame Generation" << endl;
	cout << "Input the Temperature in Degrees Celcius: ";
	string temp;
	getline(cin, temp);
	inputValidatorResponse<WeatherParam<float>> response = temperatureInputHandler(temp);
	if (response.isQuit) {
		
	}

}

static inputValidatorResponse<WeatherParam<float>> temperatureInputHandler(string s_input) {
	if (s_input == "cancel" || s_input == "quit" || s_input == "q") {
		return new inputValidatorResponse<float>(true); //only quit signal
	}
	if (s_input == "n/a") {
		return new inputValidatorResponse<float>(false, false); //invalid signal
	}

}

template <typename t>
struct inputValidatorResponse {
	bool isQuit;
	bool isValid;
	t value;
	inputValidatorResponse() : isQuit(false), isValid(false) {}
	inputValidatorResponse(bool _isQuit) : isQuit(_isQuit), isValid(false) {}
	inputValidatorResponse(bool _isQuit, bool _isValid) : isQuit(_isQuit), isValid(_isValid) {}
	inputValidatorResponse(bool _isQuit, bool _isValid, t _value) : isQuit(_isQuit), isValid(_isValid), value(_value) {}
};

