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
		char usrInYN = '\0';
	//opening user info file
		fout.open("TOSUsrInfo.tos", ios::app);
		while (vars.firstrun == true || vars.newUser == true) {
			fill_n(uvars.usrSettings, 5, 0);
			sFuncts.gui();
			cout << vars.lt << vars.pt << " Hello! Welcome to Thresshold_" << endl;
			cout << vars.lt << vars.pt << " Please enter the user name you'd like to use:";
			cin >> vars.temp;
			fout << vars.temp << endl;;
			tempUsrName = vars.temp;
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
			cout << endl;

			fout << vars.temp;
			fout.flush();
			cout << vars.lt << vars.pt << " Password written to file successfully" << endl;
			Sleep(100);
			cout << vars.lt << vars.pt << " Closing File....." << endl;
			fout << endl;
			fout.close();
			cout << vars.lt << vars.pt << " Begining Generation of User Data File..." << endl << endl;
			fout.open(tempUsrName);
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
				cout << value;//debug
			}
			cin.get();//debug
			cin.get();//debug
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