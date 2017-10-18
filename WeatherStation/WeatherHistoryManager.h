#pragma once
class WeatherHistoryManager
{
public:
	WeatherHistoryManager();
	std::string getNewestFrame();
	void addNewFrame(WeatherStation::Structs::WeatherFrame newWeatherFrame);
	std::string getCompleteHistory();
	int getHistoryPointer();
	int getHistorySize();
};

