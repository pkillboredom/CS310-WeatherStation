#include "stdafx.h"
#include "WeatherHistoryManager.h"
#include "WeatherFrame.h"
#include <array>
#include <sstream>

const int HistorySize = 4;

std::array <WeatherStation::Structs::WeatherFrame, HistorySize> weatherFrameArray;
int stackPointer;

WeatherHistoryManager::WeatherHistoryManager()
{
	stackPointer = -1;
}

void WeatherHistoryManager::addNewFrame(WeatherStation::Structs::WeatherFrame newWeatherFrame) {
	if (stackPointer >= HistorySize) {
		//This should never happen but if it does lets warn.
		std::cout << "You reached some code you really shouldnt have in the WeatherHistoryManager. Tell the programmer: StackPointerHigh";
		stackPointer = HistorySize - 1;
	}
	//refers to stackPointer + 1 as the pointer points to the last *filled* slot, not the unfilled slot.
	else if ((stackPointer + 1) == HistorySize) {
		std::array <WeatherStation::Structs::WeatherFrame, 4> tempArray;
		for (int i = 1; i < (stackPointer + 1); i++) {
			tempArray[i - 1] = weatherFrameArray[i];
		}
		tempArray[stackPointer] = newWeatherFrame;
		weatherFrameArray = tempArray;
	}
	else if ((stackPointer + 1) < HistorySize) {
		weatherFrameArray[stackPointer + 1] = newWeatherFrame;
		stackPointer++;
	}
	else {
		std::cout << "You reached some code you really shouldnt have in the WeatherHistoryManager. Tell the programmer: StackPointerLow";
	}
}

std::string WeatherHistoryManager::getNewestFrame() {
	std::ostringstream stream;
	stream << weatherFrameArray[stackPointer];
	return stream.str();
}

std::string WeatherHistoryManager::getCompleteHistory() {
	std::ostringstream stream;
	stream << "\nThe weather history in order from newest to oldest frames:";
	for (int i = stackPointer; i >= 0; i--) {
		stream << "\n\nFrame Index " << i << ":\n" << weatherFrameArray[i];
	}
	return stream.str();
}

int WeatherHistoryManager::getHistoryPointer() {
	return stackPointer;
}

int WeatherHistoryManager::getHistorySize() {
	return HistorySize;
}
