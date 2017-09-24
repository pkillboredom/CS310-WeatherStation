// WeatherStation.cpp : Defines the entry point for the console application.
//Author Luke Tomkus
//

#include "stdafx.h"
#include "ManualFrameEntryModule.h"

using namespace std;
const bool manualInputMode = true;

int main()
{
	if (manualInputMode) {
		WeatherStation::Structs::WeatherFrameResponse res = WeatherStation::InputPrompt();
		if (res.isQuit == true) {
			cout << "The user quit entry!" << endl;
		}
		else if (res.isDeny == true) {
			cout << "The user entered their data incorrectly and therefore quit." << endl;
		}
		else {
			cout << std::endl;
			cout << res.weatherFrame;
		}
	}
	else {
		cout << "Implement me, capt'n!";
		return(0);
	}
}

static int yesNoCheck(string input) {
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