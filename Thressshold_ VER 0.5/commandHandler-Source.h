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
//dll .h files
#include <Expansion.h>//this is a dll file
//dll stuff
ExpansionPack::excommands excom;//this puts a namespace and a class name to a ne
//there are many reasons that I would do the following but the main one is that these don't need to be used anywhere else
static int localUsrIn1[2];//int input currenly has 2 slots

static string localUsrIn2[2] = {"", ""};//string input curently has 2 slots
static bool comFound;

void systemFunctions::commandHandler() {
	if (!vars.usrin.compare("exit")) {

		sFuncts.killTOS();
	}

	else if (!vars.usrin.compare("newUser")) {
		vars.usrin = "";
		cout << vars.lt << vars.pt << "Loading first run....";
		vars.newUser = true;
		uFuncts.firstRun();
		//logs out the current user
		uvars.actUsr = "";
		uvars.actUsrPasswd = "";
	}

	//debug stuff bellow_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
	else if (!vars.usrin.compare("debug")) {
		vars.usrin = "";
		if (uvars.usrSettings[0] == 0) {//if the user is NOT a developer run this
			cout << vars.lt << vars.pt << "Welcome to Debug Mode. Your account does not appear to be a developer account. We are sending you to the log in screen...";
			//logs out current user
			cout << vars.lt << vars.pt << "Press any key to log out" << endl;
			uvars.actUsr = "";
			uvars.actUsrPasswd = "";
			sFuncts.clrscrn();
			//sends you to the login page
			uFuncts.loginTOS();
		}
		else if (uvars.usrSettings[0] == 1) {
			cout << vars.lt << vars.pt << "Welcome to debug mode, " << uvars.actUsr << endl;
			dvars.devModeEnabled = true;
			while (dvars.devModeEnabled == true) {
				cout << vars.lt << vars.pt << uvars.actUsr << "@Debug~ ";
				cin >> dvars.devIn;
				cout << endl;
				debugConsole();
				dvars.devIn = "";

			}
		}
	}


	else if (!vars.usrin.compare("color")) {
		vars.usrin = "";
		//cin >> localUsrIn1[0];
		cout << " 0 ";//we really should not have the user any thing as the only valid input is 0 for the first slot
		localUsrIn1[0] = 0;//sets the userinput to zero
		cin >> localUsrIn1[1];
		sFuncts.color(localUsrIn1[0], localUsrIn1[1]);

	}

	else if (!vars.usrin.compare("save")) {
		

	}
	else if (!vars.usrin.compare("clear")) {
		sFuncts.clrscrn();
		sFuncts.gui();
		vars.usrin = "";
	}
	else if (!vars.usrin.compare("ver")) {
		cout << vars.lt << vars.pt << pname << " " << vars.sysID << " " << vars.majorVer << "." << vars.minorVer << " rev " << vars.rev << endl;
		cout << vars.lt << vars.pt;
		excom.expanVer();
	}

	else {
		vars.usrin = localUsrIn2[0];
		excom.commandHandler(localUsrIn2[0]);
	}



	//clearing all local arrays and vars
	fill_n(localUsrIn1, 2, 0);//clears int varable and fills with zeros
	fill_n(localUsrIn2, 2, "");//clears string varable and fills with nothing
}