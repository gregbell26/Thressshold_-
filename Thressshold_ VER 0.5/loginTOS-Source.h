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

int userFunctions::loginTOS() {
	//int av = 5;//locally defined variable for the max amount of users and passwords
	bool loginS = false;
	int loginA = 0;
	ifstream fin;//file input 
	//ofstream fout;//fie output
	char ch;
	fin.open("TOSUsrInfo.ths");
	//nosense to get all the avaiable user information into memory. For debug porpose it does not leave
	//var set 1
	fin >> uvars.avaiableUsers[1];
	fin >> uvars.avaiablePasswords[1];
	//var set 2
	fin >> uvars.avaiableUsers[2];
	fin >> uvars.avaiablePasswords[2];
	//var set 3
	fin >> uvars.avaiableUsers[3];
	fin >> uvars.avaiablePasswords[3];
	//var set 4
	fin >> uvars.avaiableUsers[4];
	fin >> uvars.avaiablePasswords[4];
	//var set 5
	fin >> uvars.avaiableUsers[5];
	fin >> uvars.avaiablePasswords[5];
	//------------------
	fin.close();
	sFuncts.gui();
	while (loginS == false && loginA <= 5 ) {
		cout << endl;
		cout << vars.lt << vars.pt << "Please Login" << endl;
		cout << vars.lt << vars.pt << "Enter User Name: ";
		cin >> vars.usrin;
		cout << endl;
		cout << vars.lt << vars.pt << "Enter Password for the User " << vars.usrin << ": ";
		//cin >> vars.temp;
		ch = _getch();
		while (ch != 13) {
			vars.temp.push_back(ch);// inputs password in to temp
			cout << "*";
			ch = _getch();
		}
		cout << endl;
		cout << vars.lt << vars.pt << "Checking User Info... ";
		if (!uvars.avaiableUsers[1].compare(vars.usrin) || !uvars.avaiableUsers[2].compare(vars.usrin) || !uvars.avaiableUsers[3].compare(vars.usrin) || !uvars.avaiableUsers[4].compare(vars.usrin) || !uvars.avaiableUsers[5].compare(vars.usrin)) {
			cout << " | User Name - Valid ";
			if (!uvars.avaiablePasswords[1].compare(vars.temp) || !uvars.avaiablePasswords[2].compare(vars.temp) || !uvars.avaiablePasswords[3].compare(vars.temp) || !uvars.avaiablePasswords[4].compare(vars.temp) || !uvars.avaiablePasswords[5].compare(vars.temp)) {
				cout << " | Password - Valid" << endl;
				cout << vars.lt << vars.pt << "Welcome to Thresshold_ " << endl;
				uvars.actUsr = vars.usrin;
				
				vars.usrin = "";//clar userin var
				uvars.actUsrPasswd = vars.temp;
				vars.temp = "";//clear temp var
				loginS = true;
				vars.sysActive = true;
			
			}
			else {
				vars.temp = "";
				cout << " | Password - Invaild | Login Failed";
				loginA++;
			}
		}
		else {
			vars.temp = "";
			cout << " | User Name - Invaild | Login Failed";
			loginA++;
		}

		
	}
	if (loginS == true) {
		fin.open(uvars.actUsr);//open the now active user's data file
		//cin.get();//debug
		if (fin.good()) {
			cout << vars.lt << vars.pt << "User Data File Found" << endl;//if we find the file and it is not curruted load the data from it 
			fin >> uvars.usrSettings[0];
			fin >> uvars.usrSettings[1];
			fin >> uvars.usrSettings[2];
			fin >> uvars.usrSettings[3];
			fin >> uvars.usrSettings[4];
		}
		else {
			cout << vars.lt << vars.pt << "We could not find that user's data file. Login Halted. " << endl;
			cout << vars.lt << vars.pt << "Press any key to quit Thresshold_" << endl;
			cin.get();
			sFuncts.killTOS();
		}

	}

	else if (loginA > 5) {
		sFuncts.killTOS();
	}

	//Sleep(500);//debug
	
	return 0;



}