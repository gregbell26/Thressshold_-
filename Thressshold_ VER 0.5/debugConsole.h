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
/*
*This is a mess. 
*
*/

using namespace std;
int debugConsole(){
	bool active = false;
	if (!dvars.devIn.compare("variables.h")) {
		active = true;
		while (active == true) {
			dvars.devIn = "";
			cout << vars.lt << vars.pt << "TriHard@Debug/variables.h~";
			cin >> dvars.devIn;
			cout << endl;
			if (!dvars.devIn.compare("uVars")) {
				dvars.devIn = "";
				cout << vars.lt << vars.pt << "TriHard@Debug/variables.h/uVars~";
				cin >> dvars.devIn;
				cout << endl;
				if (!dvars.devIn.compare("print")) {//this command prints out the contents of the uVars class. It will be cleared in later builds but it needs to be here for debug purpose
					dvars.devIn = "";
					cout << vars.lt << vars.pt << "TriHard@Debug/variables.h/uVars~" << endl;
					cout << vars.lt << vars.pt;
					cout << uvars.actUsrPasswd << " " <<// there has to be a better way to do this. serousy. 
						uvars.actUsr << " " <<
						uvars.avaiableUsers[1] << " " <<
						uvars.avaiablePasswords[1] << " " << 
						uvars.avaiableUsers[2] << " " <<
						uvars.avaiablePasswords[2] << " " <<
						uvars.avaiableUsers[3] << " " <<
						uvars.avaiablePasswords[3] << " " <<
						uvars.avaiableUsers[4] << " " <<
						uvars.avaiablePasswords[4] << " " <<
						uvars.avaiableUsers[5] << " " <<
						uvars.avaiablePasswords[5] << " " <<						
						endl;
				}
				if (!dvars.devIn.compare("userInfo")) {
					cout << vars.lt << vars.pt;
					for (auto const& value : uvars.usrSettings)
					{
						cout << value;
					}
					cout << endl;
				}
			}
			else if (!dvars.devIn.compare("exit")) {
				active = false;

			}
	
		}

	}

	else if (!dvars.devIn.compare("exit")) {
		dvars.devModeEnabled = false;
	}
	else {
		cout << vars.lt << vars.pt << "Bad .h file name" << endl;
	}
	return 0;
}