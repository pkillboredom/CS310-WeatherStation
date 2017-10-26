#pragma once

class WeatherHistoryManager
{
public:
	WeatherStation::Structs::WeatherFrame** weatherFrameArray;
	int stackPointer;
	int historySize;

	WeatherHistoryManager(int size);
	std::string getNewestFrame();
	void addNewFrame(WeatherStation::Structs::WeatherFrame newWeatherFrame);
	std::string getCompleteHistory();
	int getHistoryPointer();
	int getHistorySize();
};

