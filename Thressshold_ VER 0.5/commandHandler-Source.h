#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
//.h files
#include "variables.h"
#include "systemFunctions.h"
#include "bootAnimation.h"
#include "userFunctions.h"
#include "debugConsole.h"
#include "User-Source\User.h"
//dll .h files
#include <Expansion.h>//this is a dll file
//dll stuff
ExpansionPack::excommands excom;//this puts a namespace and a class name to a ne
//there are many reasons that I would do the following but the main one is that these don't need to be used anywhere else
static int localUsrIn1[2];//int input currenly has 2 slots

static string localUsrIn2[2] = {"", ""};//string input curently has 2 slots
void systemFunctions::commandHandler(string usrIn) {
	if (!usrIn.compare("exit")) {

		sFuncts.killTOS();
	}

	else if (!usrIn.compare("newUser")) {
		usrIn = "";
		cout << vars.lt << vars.pt << "Loading first run....";
		User.logOff();
		User.newUserVar = true;
		User.firstRun();
		User.logOn();

	}

	//debug stuff bellow_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
	else if (!usrIn.compare("debug")) {
		usrIn = "";
		if (!User.isDev()) {//if the user is NOT a developer run this
			cout << vars.lt << vars.pt << "Welcome to Debug Mode. Your account does not appear to be a developer account. We are sending you to the log in screen..." << endl;
			//logs out current user
			cout << vars.lt << vars.pt << "Press any key to log out" << endl;
			cin.get();
			cin.get();
			User.logOff();
			sFuncts.clrscrn();
			//sends you to the login page
			User.logOn();
		}
		else {
			cout << vars.lt << vars.pt << "Welcome to debug mode, " << User.getActiveUser() << endl;
			dvars.devModeEnabled = true;
			while (dvars.devModeEnabled == true) {
				cout << vars.lt << vars.pt << User.getActiveUser() << "@Debug~ ";
				cin >> dvars.devIn;
				cout << endl;
				debugConsole();
				dvars.devIn = "";

			}
		}
	}


	else if (!usrIn.compare("color")) {
		usrIn = "";
		//cin >> localUsrIn1[0];
		cout << " 0 ";//we really should not have the user any thing as the only valid input is 0 for the first slot
		localUsrIn1[0] = 0;//sets the userinput to zero
		cin >> localUsrIn1[1];
		sFuncts.color(localUsrIn1[0], localUsrIn1[1]);

	}

	else if (!usrIn.compare("save")) {
		

	}
	else if (!usrIn.compare("clear")) {
		sFuncts.clrscrn();
		sFuncts.gui();
		usrIn = "";
	}
	else if (!usrIn.compare("ver")) {
		cout << vars.lt << vars.pt << pname << " " << vars.sysID << " " << vars.majorVer << "." << vars.minorVer << " rev " << vars.rev << endl;
		cout << vars.lt << vars.pt;
		excom.expanVer();
	}

	else if (!usrIn.compare("logout")) {
		cout << vars.lt << vars.pt << " Press any key to log off of Thresshold_" << endl;
		cin.get();
		cout << vars.lt << vars.pt << " Logging off..." << endl;
		User.logOff();
	}

	else if (!excom.commandHandler(usrIn)) {
		cout << vars.lt << vars.pt << " That does not appear to be a valid command. Please check you spelling." << endl;
	}


	//clearing all local arrays and vars
	fill_n(localUsrIn1, 2, 0);//clears int varable and fills with zeros
	fill_n(localUsrIn2, 2, "");//clears string varable and fills with nothing
}