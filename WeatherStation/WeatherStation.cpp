// WeatherStation.cpp : Defines the entry point for the console application.
//Author Luke Tomkus

#pragma once

#include "stdafx.h"
#include "ManualFrameEntryModule.h"
#include "WeatherFrame.h"
#include "WeatherHistoryManager.h"
#include <stack>

using namespace std;



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


int main()
{
	cout << "Welcome to the Weather Station System.\n" << endl;

	bool menumode = false;
	bool namemode = true;
	bool historymode = true;
	bool menuQuit = false;
	WeatherStation::Structs::WeatherFrame lastFrame;
	bool frameEntered = false;
	string stationname;
	int histlen = 1;
	WeatherHistoryManager historyManager(1);

	while (!menuQuit) {

		if (namemode) {
			//section for station name
			cout << "What would you like to name your station?\nStation Name: ";
			string tempa;
			getline(cin, tempa);
			cout << "Is \'" << tempa << "\' the name you want? Y/N: ";
			string tempb;

			int yn = 2;
			while (yn != 0 || yn != 1) {
				getline(std::cin, tempb);
				yn = yesNoCheck(tempb);
				if (yn == 1) {
					stationname = tempa;
					menumode = false;
					namemode = false;
					break;
				}
				else if (yn == 0) {
					menumode = false;
					namemode = true;
					break;
				}
				else {
					std::cout << "That was not a valid entry." << std::endl;
					std::cout << "Is the name correct? (Y/N): ";
				}
			}
		}

		if (historymode) {
			cout << "How long would you like the history to be? (Max 65,535, Min 1)\nHistory Size: ";
			string temph;
			getline(cin, temph);
			try {
				int tempHistLen = stoi(temph);
				if (tempHistLen < 1 || tempHistLen > 65535) {
					cout << "That was not a valid entry." << endl;
					historymode = true;
					menumode = false;
				}
				else {
					cout << "Is \'" << tempHistLen << "\' the size you want? (This will use " << tempHistLen*sizeof(WeatherStation::Structs::WeatherFrame) << " bytes) Y/N: ";
					string tempb;

					int yn = 2;
					while (yn != 0 || yn != 1) {
						getline(std::cin, tempb);
						yn = yesNoCheck(tempb);
						if (yn == 1) {
							histlen = tempHistLen;
							historymode = false;
							menumode = true;
							break;
						}
						else if (yn == 0) {
							historymode = true;
							menumode = false;
							break;
						}
						else {
							std::cout << "That was not a valid entry." << std::endl;
							std::cout << "Is the History Size correct? (Y/N): ";
						}
					}
				}
			}
			catch (std::exception e) {
				cout << "That was not a valid entry." << endl;
				historymode = true;
				menumode = false;
			}
			if (!historymode) {
				historyManager = WeatherHistoryManager(histlen);
			}
		}


		if (menumode) {

			cout << "Directory " << endl;
			cout << "------------------------------" << endl;
			cout << "0. Quit" << endl;
			cout << "1. Manual Weather Frame Entry." << endl;
			cout << "2. View Last Entered Frame. (Current Weather)" << endl;
			cout << "3. View Entire Weather History." << endl;
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
						if (historyManager.getHistoryPointer() + 1 >= historyManager.getHistorySize()) {
							cout << "This will delete the oldest entry." << endl;
						}
						//Calls function from ManualFrameEntryModule.cpp
						//returns a response struct with either a quit signal, invalid signal, or a valid weather frame.
						res = WeatherStation::InputPrompt(stationname);
						if (res.isQuit == true) {
							cout << "The user quit entry!" << endl;
							break;
						}
						else if (res.isDeny == true) {
							cout << "The user entered their data incorrectly and therefore quit entry." << endl;
							break;
						}
						else {
							cout << std::endl;
							historyManager.addNewFrame(res.weatherFrame);
							frameEntered = true;
						}
						break;
					};
					case 2:
						//see last entry case
						validEntry = true;
						if (frameEntered) {
							cout << "\nThe last frame input:\n";
							cout << historyManager.getNewestFrame() << std::endl;
						}
						else {
							cout << "\nNo frame has been entered." << std::endl;
						}
						break;
					case 3:
						validEntry = true;
						if (frameEntered) {
							cout << historyManager.getCompleteHistory() << endl << endl;
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
	}
	exit(0);
}