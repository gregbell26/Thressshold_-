#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "variables.h"
#include "systemFunctions.h"
#include "bootAnimation.h"
#include "userFunctions.h"
#include "debugConsole.h"


int userFunctions::firstRun() {

	if (vars.firstrun == true || vars.newUser == true) {
		sFuncts.clrscrn();//clears screen
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), loginColors);//should set colors
		sFuncts.clrscrn();//clears screen
		//local varables
		ofstream fout;//command to output to a file
		string tempUsrName = "";//so we can store the user's name for the user data generation
		char ch;
		char usrInYN = '\0';// \0 is null
		bool passMatch = false;
		//end of local var defination
		CreateDirectory(L"Users", NULL);//Creating the subfolder for user stuff
		SetCurrentDirectory(L"Users");//seting the current dir
	//opening user info file
		fout.open("TOSUsrInfo.ths", ios::app /*| ios::binary*/);//.ths will be file extendsion for this program Also ios app places the writer at the end of the file. 
		while (vars.firstrun == true || vars.newUser == true) {
			fill_n(uvars.usrSettings, 5, 0);//clears the user setting array
			sFuncts.gui();
			cout << vars.lt << vars.pt << " Hello! Welcome to Thresshold_" << endl;
			cout << vars.lt << vars.pt << " Please enter the user name you'd like to use: ";
			cin >> vars.temp;//inputs user name in temp
			fout << vars.temp << endl;;
			tempUsrName = vars.temp;//stores user name 
			vars.temp = "";
			fout.flush();
			cout << vars.lt << vars.pt << " User name written to file successfully" << endl;
			cout << vars.lt << vars.pt << " Please enter the password you'd like to use: ";
			ch = _getch();
			while (ch != 13) {
				vars.temp.push_back(ch);// inputs password in to temp
				cout << "*";
				ch = _getch();
			}
			cout << endl;
			while (passMatch == false) {
				cout << vars.lt << vars.pt << " Please enter your password again: ";
				ch = _getch();
				while (ch != 13) {
					vars.usrin.push_back(ch);// inputs password in to usrin to we can check if matches the other password
					cout << "*";
					ch = _getch();
				}
				cout << endl;
				if (!vars.temp.compare(vars.usrin)) {
					passMatch = true;
				}
				else {
					cout << vars.lt << vars.pt << " Your password did not match. Lets try again" << endl;
				}
				vars.usrin = "";
			}
			cout << vars.lt << vars.pt << " Passwords match. Writing to file.." << endl;
			fout << vars.temp;
			fout.flush();
			cout << vars.lt << vars.pt << " Password written to file successfully" << endl;
			Sleep(100);
			cout << vars.lt << vars.pt << " Closing File....." << endl;
			fout << endl;
			fout.close();
			cout << vars.lt << vars.pt << " Begining Generation of User Data File..." << endl << endl;
			fout.open(tempUsrName);//this will create a user data file with the users name 
			cout << vars.lt << vars.pt << " Is this a developer account? (y/n): ";
			cin >> usrInYN;
			if (usrInYN == 'y' || usrInYN == 'Y') {
				uvars.usrSettings[0] = 1;
			}
			usrInYN = '\0';
			cout << endl;
			cout << vars.lt << vars.pt << " Should this account be admin? (y/n): ";
			cin >> usrInYN;
			if (usrInYN == 'y' || usrInYN == 'Y') {
				uvars.usrSettings[1] = 1;
			}
			usrInYN = '\0';
			cout << endl;
			cout << vars.lt << vars.pt << " Writting user data to file..." << endl;
			for (auto const& value : uvars.usrSettings)
			{
				fout << value;
				fout << endl;
			}
			fout.close();
			cout << vars.lt << vars.pt << " Ending User Generation" << endl;
			vars.firstrun = false;
			vars.newUser = false;
			vars.ready = true;
			Sleep(100);

			/*cout << vars.lt << vars.pt << "Resarting........" << endl;
			Sleep(1000);
			sFuncts.restartTOS();*/

		}
	}


	return 0;

}