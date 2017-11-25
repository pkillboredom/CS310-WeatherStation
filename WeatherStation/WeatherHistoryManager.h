#pragma once

class WeatherHistoryManager
{
public:
	WeatherStation::Structs::WeatherMeasurement* WeatherMeasurementArray;
	int stackPointer;
	int historySize;

	WeatherHistoryManager(int size);
	std::string getNewestFrame();
	void addNewFrame(WeatherStation::Structs::WeatherMeasurement newWeatherMeasurement);
	std::string getCompleteHistory();
	int getHistoryPointer();
	int getHistorySize();
};

