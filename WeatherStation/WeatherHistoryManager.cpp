#pragma once

#include "stdafx.h"
#include "WeatherHistoryManager.h"
#include "WeatherFrame.h"
#include <array>
#include <sstream>

std::string windDirectionArr[] = { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };

WeatherHistoryManager::WeatherHistoryManager(int size)
{
	stackPointer = -1;
	weatherFrameArray = new WeatherStation::Structs::WeatherFrame*[size];
	historySize = size;
}

void WeatherHistoryManager::addNewFrame(WeatherStation::Structs::WeatherFrame newWeatherFrame) {
	if (stackPointer >= historySize) {
		//This should never happen but if it does lets warn.
		std::cout << "You reached some code you really shouldnt have in the WeatherHistoryManager. Tell the programmer: StackPointerHigh";
		stackPointer = historySize - 1;
	}
	//refers to stackPointer + 1 as the pointer points to the last *filled* slot, not the unfilled slot.
	else if ((stackPointer + 1) == historySize) {
		WeatherStation::Structs::WeatherFrame** tempArray = new WeatherStation::Structs::WeatherFrame*[historySize];
		for (int i = 1; i < (stackPointer + 1); i++) {
			tempArray[i - 1] = weatherFrameArray[i];
		}
		tempArray[stackPointer] = &newWeatherFrame;
		weatherFrameArray = tempArray;
	}
	else if ((stackPointer + 1) < historySize) {
		weatherFrameArray[stackPointer + 1] = &newWeatherFrame;
		stackPointer++;
	}
	else {
		std::cout << "You reached some code you really shouldnt have in the WeatherHistoryManager. Tell the programmer: StackPointerLow";
	}
}

std::string WeatherHistoryManager::getNewestFrame() {
	std::ostringstream stream;
	stream << "Temperature = " << (weatherFrameArray[stackPointer]->Temperature.value) << "\nWind Speed = " << (weatherFrameArray[stackPointer]->WindSpeed.value) << "\nWind Direction = ";
	int windval = weatherFrameArray[stackPointer]->WindDirection.value;
	if (windval >= 0 && windval < 16) {
		stream << windDirectionArr[windval] << "\n";
	}
	else {
		stream << "Unavailiable\n";
	}
	stream << std::endl;
	return stream.str();
}

std::string WeatherHistoryManager::getCompleteHistory() {
	std::ostringstream stream;
	stream << "\nThe weather history in order from newest to oldest frames:";
	for (int i = stackPointer; i >= 0; i--) {
		stream << "\n\nFrame Index " << i << ":\n";
		stream << "Temperature = " << (weatherFrameArray[i]->Temperature.value) << "\nWind Speed = " << (weatherFrameArray[i]->WindSpeed.value) << "\nWind Direction = ";
		int windval = weatherFrameArray[i]->WindDirection.value;
		if (windval >= 0 && windval < 16) {
			stream << windDirectionArr[windval] << "\n";
		}
		else {
			stream << "Unavailiable\n";
		}
		stream << std::endl;
	}
	return stream.str();
}

int WeatherHistoryManager::getHistoryPointer() {
	return stackPointer;
}

int WeatherHistoryManager::getHistorySize() {
	return historySize;
}