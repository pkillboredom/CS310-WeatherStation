// WeatherStation.cpp : Defines the entry point for the console application.
//Author Luke Tomkus

#include "stdafx.h"
#include "ManualFrameEntryModule.h"

using namespace std;
const bool manualInputMode = true;

int main()
{
	//proj3
	cout << "Welcome to the Weather Station System.\n" << endl;
	bool menuQuit = false;
	WeatherStation::Structs::WeatherFrame lastFrame;
	bool frameEntered = false;
	while (!menuQuit) {
		cout << "Directory " << endl;
		cout << "------------------------------" << endl;
		cout << "0. Quit" << endl;
		cout << "1. Manual Weather Frame Entry." << endl;
		cout << "2. View Last Entered Frame." << endl;
		cout << "------------------------------" << endl;
		cout << "Enter an option: ";
		bool validEntry = false;
		bool firstTimePrompting = true;
		string temp;
		int entry = -1;
		while (!validEntry) {
			if (!firstTimePrompting) {
				cout << "Your entry was invalid. Enter an option: ";
			}
			getline(cin, temp);
			try {
				entry = stoi(temp);
				switch (entry) {
				case 0:
					//quit case
					validEntry = true;
					menuQuit = true;
					break;
				case 1: {
					//manual frame case
					validEntry = true;
					WeatherStation::Structs::WeatherFrameResponse res;
					//Calls function from ManualFrameEntryModule.cpp
					//returns a response struct with either a quit signal, invalid signal, or a valid weather frame.
					res = WeatherStation::InputPrompt();
					if (res.isQuit == true) {
						cout << "The user quit entry!" << endl;
						break;
					}
					else if (res.isDeny == true) {
						cout << "The user entered their data incorrectly and therefore quit." << endl;
						break;
					}
					else {
						cout << std::endl;
						lastFrame = res.weatherFrame;
						frameEntered = true;
					}
					break;
				};
				case 2:
					//see last entry case
					validEntry = true;
					if (frameEntered) {
						cout << "\nThe last frame input:\n";
						cout << lastFrame << std::endl;
					}
					else {
						cout << "\nNo frame has been entered." << std::endl;
					}
					break;
				default:
					validEntry = false;
					break;
				}
			}
			catch (exception e) {
				validEntry = false;
			}
			firstTimePrompting = false;
		}
	}
	exit(0);
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