//Author Luke Tomkus

#include "stdafx.h"
#include <string>
#include "inputValidatorResponse.h"
#include "WeatherFrameResponse.h"
#include "ManualFrameEntryModule.h"

using namespace WeatherStation;
using namespace WeatherStation::Structs;

namespace WeatherStation {

	static inputValidatorResponse<std::string> stringInputHandler(std::string s_input, std::string name) {
		if (s_input == "cancel" || s_input == "quit" || s_input == "q") {
			std::cout << "debug_floatquit\n";
			return inputValidatorResponse<std::string>(true); //only quit signal
		}
		if (s_input == "n/a") {
			return inputValidatorResponse<std::string>(false, false, WeatherParam<std::string>("Unavailiable", false, name)); //invalid signal
		}
		else {
			if (s_input == "") {
				return inputValidatorResponse<std::string>(false, 2, WeatherParam<std::string>(name));
			}
			else {
				return inputValidatorResponse<std::string>(false, 1, WeatherParam<std::string>(s_input, true, name));
			}
		}
	}

	static inputValidatorResponse<float> floatInputHandler(std::string s_input, std::string name) {
		if (s_input == "cancel" || s_input == "quit" || s_input == "q") {
			std::cout << "debug_floatquit\n";
			return inputValidatorResponse<float>(true); //only quit signal
		}
		if (s_input == "n/a") {
			return inputValidatorResponse<float>(false, false, WeatherParam<float>(0, false, name)); //invalid signal
		}
		else {
			float f_out;
			try {
				f_out = std::stof(s_input);
				//std::cout << "debug_f_out: " << f_out;
				return inputValidatorResponse<float>(false, 1, WeatherParam<float>(f_out, true, name));
			}
			catch (std::exception e) {
				return inputValidatorResponse<float>(false, 2, WeatherParam<float>(0, false, name));
			}
		}
	}

	static inputValidatorResponse<WindDirections> windDirectionInputHandler(std::string s_input, std::string name) {
		if (s_input == "cancel" || s_input == "quit" || s_input == "q") {
			return inputValidatorResponse<WindDirections>(true); //only quit signal
		}
		if (s_input == "n/a") {
			return inputValidatorResponse<WindDirections>(false, false); //std::invalid signal
		}
		else { //obviously this is gross, but we only use it for manual input checking, not internal generation.
			if (s_input == "n" || s_input == "N") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(N, name));
			}
			else if (s_input == "nne" || s_input == "NNE") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(NNE, name));
			}
			else if (s_input == "ne" || s_input == "NE") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(NE, name));
			}
			else if (s_input == "ene" || s_input == "ENE") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(ENE, name));
			}
			else if (s_input == "e" || s_input == "E") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(E, name));
			}
			else if (s_input == "ese" || s_input == "ESE") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(ESE, name));
			}
			else if (s_input == "se" || s_input == "SE") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(SE, name));
			}
			else if (s_input == "sse" || s_input == "SSE") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(SSE, name));
			}
			else if (s_input == "s" || s_input == "S") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(S, name));
			}
			else if (s_input == "ssw" || s_input == "SSW") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(SSW, name));
			}
			else if (s_input == "sw" || s_input == "SW") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(SW, name));
			}
			else if (s_input == "wsw" || s_input == "WSW") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(WSW, name));
			}
			else if (s_input == "w" || s_input == "W") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(W, name));
			}
			else if (s_input == "wnw" || s_input == "WNW") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(WNW, name));
			}
			else if (s_input == "nw" || s_input == "NW") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(NW, name));
			}
			else if (s_input == "nnw" || s_input == "NNW") {
				return inputValidatorResponse<WindDirections>(false, 1, WeatherParam<WindDirections>(NNW, name));
			}
			else {
				return inputValidatorResponse<WindDirections>(false, 2, WeatherParam<WindDirections>(N, false, name));
			}
		}
	}

	static inputValidatorResponse<Percentage> percentageInputHandler(std::string s_input, std::string name) {
		if (s_input == "cancel" || s_input == "quit" || s_input == "q") {
			return inputValidatorResponse<Percentage>(true); //only quit signal
		}
		if (s_input == "n/a") {
			return inputValidatorResponse<Percentage>(false, false); //std::invalid signal
		}
		else {
			int val = 0;
			try {
				val = std::stoi(s_input);
			}
			catch (std::exception e) {
				return inputValidatorResponse<Percentage>(false, 2, WeatherParam<Percentage>(false, false, name));
			}
			if (val < 0 || val > 100) {
				return inputValidatorResponse<Percentage>(false, 2, WeatherParam<Percentage>(false, false, name));
			}
			else {
				return inputValidatorResponse<Percentage>(false, true, WeatherParam<Percentage>(val, name));
			}
		}
	}

	static inputValidatorResponse<int> intInputHandler(std::string s_input, std::string name) {
		if (s_input == "cancel" || s_input == "quit" || s_input == "q") {
			return inputValidatorResponse<int>(true); //only quit signal
		}
		if (s_input == "n/a") {
			return inputValidatorResponse<int>(false, false); //std::invalid signal
		}
		else {
			int f_out;
			try {
				f_out = std::stoi(s_input);
				return inputValidatorResponse<int>(false, 1, WeatherParam<int>(f_out, name));
			}
			catch (std::exception e) {
				return inputValidatorResponse<int>(false, 2);
			}
		}
	}

	static int yesNoCheck(std::string input) {
		if (input == "y" || input == "Y") {
			return 1;
		}
		else if (input == "n" || input == "N") {
			return 0;
		}
		else {
			return 2;
		}
	}

	WeatherFrameResponse InputPrompt() {

		///take in std::strings so that the professor cant throw exceptions on bad inputs
		std::string s_name;
		std::string s_temperature;
		//std::string s_feelsLikeTemperature;
		//std::string s_heatIndex;
		//std::string s_dewPoint;
		std::string s_windSpeed;
		std::string s_windDirection;
		//std::string s_visibiity;
		//std::string s_humidity;
		//std::string s_pressure;

		///input handlers convert to correct types
		WeatherParam<std::string> f_name;
		WeatherParam<float> f_temperature;
		//WeatherParam<float> f_feelsLikeTemperature;
		//WeatherParam<float> f_heatIndex;
		//WeatherParam<float> f_dewPoint;
		WeatherParam<float> f_windSpeed;
		//WeatherParam<float> f_windGust;
		WeatherParam<WindDirections> f_windDirection;
		//WeatherParam<float> f_visibility;
		//WeatherParam<Percentage> f_humidity;
		//WeatherParam<int> f_pressure;

		//Strings for the unit displays. Eventually these will be governed by options.
		std::string tempUnit = "deg C";
		std::string windUnit = "KMpH";
		std::string distUnit = "KM";
		std::string pressUnit = "hPa";

		//used for loops below
		bool undef_flag = true;
		std::string temp;

		std::cout << "\nManual Weather Frame Generation" << std::endl;
#pragma region Data Inputs

		while (undef_flag) {
			std::cout << "Input the name of the weather station: ";
			std::getline(std::cin, temp);
			WeatherStation::Structs::inputValidatorResponse<std::string> responsez = stringInputHandler(temp, "Station Name");
			//std::cout << "\ndebug_resa params: isQuit: " << responsea.isQuit << " isvalid: " << responsea.isValid << " val: " << responsea.value << " " << std::endl;
			if (responsez.isQuit) {
				//std::cout << "debug_resa isQuit\n";
				return WeatherFrameResponse(true, false);
			}
			else if (responsez.isValid == 0) {
				undef_flag = false;
				f_name = WeatherParam<std::string>("Station Name");
			}
			else if (responsez.isValid == 2) {
				std::cout << "Your input was not understood. Do you want to leave it undefined?\nY/N: ";
				temp = "";
				std::getline(std::cin, temp);
				int yn = yesNoCheck(temp);
				if (yn == 1) {
					undef_flag = false;
					f_name = WeatherParam<std::string>("Station Name");
				}
				else if (yn == 0) {
					undef_flag = true;
				}
				else {
					undef_flag = true;
					std::cout << "Didn't understand, assuming N..." << std::endl;
				}
			}
			else {
				undef_flag = false;
				f_name = responsez.value;
			}
		}
		undef_flag = true;
		while (undef_flag) {
			std::cout << "Input the Temperature in Degrees Celcius: ";
			std::getline(std::cin, temp);
			WeatherStation::Structs::inputValidatorResponse<float> responsea = floatInputHandler(temp, "Temperature");
			//std::cout << "\ndebug_resa params: isQuit: " << responsea.isQuit << " isvalid: " << responsea.isValid << " val: " << responsea.value << " " << std::endl;
			if (responsea.isQuit) {
				//std::cout << "debug_resa isQuit\n";
				return WeatherFrameResponse(true, false);
			}
			else if (responsea.isValid == 0) {
				undef_flag = false;
				f_temperature = WeatherParam<float>("Temperature");
			}
			else if (responsea.isValid == 2) {
				std::cout << "Your input was not understood. Do you want to leave it undefined?\nY/N: ";
				temp = "";
				std::getline(std::cin, temp);
				int yn = yesNoCheck(temp);
				if (yn == 1) {
					undef_flag = false;
					f_temperature = WeatherParam<float>("Temperature");
				}
				else if (yn == 0) {
					undef_flag = true;
				}
				else {
					undef_flag = true;
					std::cout << "Didn't understand, assuming N..." << std::endl;
				}
			}
			else {
				undef_flag = false;
				f_temperature = responsea.value;
			}
		}

		/*std::cout << "Input the Feels Like Temperature in Degrees Celcius: ";
		std::getline(std::cin, temp);
		inputValidatorResponse<float> responseb = floatInputHandler(temp, "Feels Like Temperature");
		if (responseb.isQuit) {
			return WeatherFrameResponse(true, false);
		}
		else if (responseb.isValid == 0) {
			f_feelsLikeTemperature = WeatherParam<float>("Feels Like Temperature");
		}
		else if (responseb.isValid == 2) {
			std::cout << "Your input was not understood. Setting as unavailiable." << std::endl;
			f_feelsLikeTemperature = WeatherParam<float>("Feels Like Temperature");
		}
		else {
			f_feelsLikeTemperature = responseb.value;
		}*/

		/*std::cout << "Input the Heat Index in Degrees Celcius: ";
		
		std::getline(std::cin, temp);
		inputValidatorResponse<float> responsec = floatInputHandler(temp, "Heat Index");
		if (responsec.isQuit) {
			return WeatherFrameResponse(true, false);
		}
		else if (responsec.isValid == 0) {
			f_heatIndex = WeatherParam<float>("Heat Index");
		}
		else if (responsec.isValid == 2) {
			std::cout << "Your input was not understood. Setting as unavailiable." << std::endl;
			f_heatIndex = WeatherParam<float>("Heat Index");
		}
		else {
			f_heatIndex = responsec.value;
		}*/

		/*std::cout << "Input the Dew Point in Degrees Celcius: ";
		
		std::getline(std::cin, temp);
		inputValidatorResponse<float> responsed = floatInputHandler(temp, "Dew Point");
		if (responsed.isQuit) {
			return WeatherFrameResponse(true, false);
		}
		else if (responsed.isValid == 0) {
			f_dewPoint = WeatherParam<float>("Dew Point");
		}
		else if (responsed.isValid == 2) {
			std::cout << "Your input was not understood. Setting as unavailiable." << std::endl;
			f_dewPoint = WeatherParam<float>("Dew Point");
		}
		else {
			f_dewPoint = responsed.value;
		}*/

		undef_flag = true;

		while (undef_flag) {
			std::cout << "Input the Wind Speed in KMpH: ";

			std::getline(std::cin, temp);
			inputValidatorResponse<float> responsee = floatInputHandler(temp, "Wind Speed");
			if (responsee.isQuit) {
				return WeatherFrameResponse(true, false);
			}
			else if (responsee.isValid == 0) {
				undef_flag = false;
				f_windSpeed = WeatherParam<float>("Wind Speed");
			}
			else if (responsee.isValid == 2) {
				std::cout << "Your input was not understood. Do you want to leave it undefined?\nY/N: ";
				temp = "";
				std::getline(std::cin, temp);
				int yn = yesNoCheck(temp);
				if (yn == 1) {
					undef_flag = false;
					f_windSpeed = WeatherParam<float>("Wind Speed");
				}
				else if (yn == 0) {
					undef_flag = true;
				}
				else {
					undef_flag = true;
					std::cout << "Didn't understand, assuming N..." << std::endl;
				}
			}
			else {
				undef_flag = false;
				f_windSpeed = responsee.value;
			}
		}

		/*std::cout << "Input the Wind Gust in KMpH: ";
		
		std::getline(std::cin, temp);
		inputValidatorResponse<float> responsef = floatInputHandler(temp, "Wind Gust");
		if (responsef.isQuit) {
			return WeatherFrameResponse(true, false);
		}
		else if (responsef.isValid == 0) {
			f_windGust = WeatherParam<float>("Wind Gust");
		}
		else if (responsef.isValid == 2) {
			std::cout << "Your input was not understood. Setting as unavailiable." << std::endl;
			f_windGust = WeatherParam<float>("Wind Gust");
		}
		else {
			f_windGust = responsef.value;
		}*/
			

		undef_flag = true;

		while (undef_flag) {

			std::cout << "Input the Wind Direction up to three levels of precision(e.g. N, SW, WNW): ";

			std::getline(std::cin, temp);
			inputValidatorResponse<WindDirections> responseg = windDirectionInputHandler(temp, "Wind Direction");
			if (responseg.isQuit) {
				return WeatherFrameResponse(true, false);
			}
			else if (responseg.isValid == 0) {
				f_windDirection = WeatherParam<WindDirections>("Wind Direction");
			}
			else if (responseg.isValid == 2) {
				std::cout << "Your input was not understood. Do you want to leave it undefined?\nY/N: ";
				temp = "";
				std::getline(std::cin, temp);
				int yn = yesNoCheck(temp);
				if (yn == 1) {
					undef_flag = false;
					f_windDirection = WeatherParam<WindDirections>("Wind Direction");
				}
				else if (yn == 0) {
					undef_flag = true;
				}
				else {
					undef_flag = true;
					std::cout << "Didn't understand, assuming N..." << std::endl;
				}
			}
			else {
				undef_flag = false;
				f_windDirection = responseg.value;
			}
		}

		/*std::cout << "Input the Visibility in KM: ";
		
		std::getline(std::cin, temp);
		inputValidatorResponse<float> responseh = floatInputHandler(temp, "Visibility");
		if (responseh.isQuit) {
			return WeatherFrameResponse(true, false);
		}
		else if (responseh.isValid == 0) {
			f_visibility = WeatherParam<float>("Visibility");
		}
		else if (responseh.isValid == 2) {
			std::cout << "Your input was not understood. Setting as unavailiable." << std::endl;
			f_visibility = WeatherParam<float>("Visibility");
		}
		else {
			f_visibility = responseh.value;
		}*/

		/*std::cout << "Input the Humidity as a percentage (excluding percent sign): ";
		
		std::getline(std::cin, temp);
		
		inputValidatorResponse<Percentage> responsei = percentageInputHandler(temp, "Humidity");
		if (responsei.isQuit) {
			return WeatherFrameResponse(true, false);
		}
		else if (responsei.isValid == 0) {
			f_humidity = WeatherParam<Percentage>("Humidity");
		}
		else if (responsei.isValid == 2) {
			std::cout << "Your input was not understood. Setting as unavailiable." << std::endl;
			f_humidity = WeatherParam<Percentage>("Humidity");
		}
		else {
			f_humidity = responsei.value;
		}*/

		/*std::cout << "Input the Pressure in hPa: ";
		
		std::getline(std::cin, temp);
		inputValidatorResponse<int> responsej = intInputHandler(temp, "Pressure");
		if (responsej.isQuit) {
			return WeatherFrameResponse(true, false);
		}
		else if (responsej.isValid == 0) {
			f_pressure = WeatherParam<int>("Pressure");
		}
		else if (responsej.isValid == 2) {
			std::cout << "Your input was not understood. Setting as unavailiable." << std::endl;
			f_pressure = WeatherParam<int>("Pressure");
		}
		else {
			f_pressure = responsej.value;
		}*/
#pragma endregion

		//This array is a temporary measure for outputting the name corresponding to the wind dir enum
		//Temporary...
		std::string windDirectionArr[] = { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };

		std::cout << std::endl;
		std::cout << "Is the following data correct?\n" << std::endl;
		std::cout << f_name << "\n";
		std::cout << f_temperature << " " << tempUnit << "\n";
		//std::cout << f_feelsLikeTemperature << " " << tempUnit << "\n";
		//std::cout << f_heatIndex << " " << tempUnit << "\n";
		//std::cout << f_dewPoint << " " << tempUnit << "\n";
		std::cout << f_windSpeed << " " << windUnit << "\n";
		//std::cout << f_windGust << " " << windUnit << "\n";
		std::cout << "Wind Direction = ";
		//temporary workaround for enum issue.
		if(f_windDirection.value >= 0 && f_windDirection.value < 16) {
			std::cout << windDirectionArr[f_windDirection.value] << "\n";
		}
		else {
			std::cout << "Unavailiable\n";
		}
		//std::cout << f_visibility << " " << distUnit << "\n";
		//std::cout << f_humidity << "\n";
		//std::cout << f_pressure << " " << pressUnit << "\n";

		std::cout << "Is the data correct? (Y/N): ";
		
		std::getline(std::cin, temp);
		int yn = 2;
		while (yn != 0 || yn != 1) {
			yn = yesNoCheck(temp);
			if (yn == 1) {
				//return WeatherFrameResponse(WeatherFrame(f_name, f_temperature, f_feelsLikeTemperature, f_heatIndex, f_dewPoint,
					//f_windSpeed, f_windGust, f_windDirection, f_visibility, f_humidity, f_pressure));
				return WeatherFrameResponse(WeatherFrame(f_name, f_temperature, f_windSpeed, f_windDirection));
			}
			else if (yn == 0) {
				return WeatherFrameResponse(false, true);
			}
			else {
				std::cout << "That was not a valid entry." << std::endl;
				std::cout << "Is the data correct? (Y/N): ";
				std::getline(std::cin, temp);
				yn = yesNoCheck(temp);
			}
		}
	}
}
