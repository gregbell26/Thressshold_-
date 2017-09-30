#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Expansion.h"
#include "variables.h"
#include "systemFunctions.h"
#include "bootAnimation.h"
#include "userFunctions.h"
#include "debugConsole.h"

//dll stuff
using namespace ExpansionPack;
excommands excom;
//there are many reasons that I would do the following but the main one is that these don't need to be used anywhere else
static int localUsrIn1[2];//int input currenly has 2 slots

static string localUsrIn2[2];//string input curently has 2 slots


void systemFunctions::commandHandler() {
	if (!vars.usrin.compare("exit")) {
		sFuncts.killTOS();
	}

	else if (!vars.usrin.compare("newUser")) {// isnt working right
		vars.usrin = "";
		cout << vars.lt << vars.pt << "Loading first run....";
		vars.newUser = true;
		uFuncts.firstRun();
	}

	//debug stuff bellow_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
	else if (!vars.usrin.compare("debug")) {
		vars.usrin = "";
		if (uvars.usrSettings[0] == 0) {//if the user is NOT a developer run this
			cout << vars.lt << vars.pt << "Welcome to Debug Mode. Your account does not appear to be a developer account. We are sending you to the log in screen...";
			sFuncts.clrscrn();
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
		cin >> localUsrIn1[0];
		cin >> localUsrIn1[1];
		sFuncts.color(localUsrIn1[0], localUsrIn1[1]);

	}
	else if (!vars.usrin.compare("clear")) {
		sFuncts.clrscrn();
		sFuncts.gui();
		vars.usrin = "";
	}
	else if (!vars.usrin.compare("ver")) {
		cout << vars.lt << vars.pt << pname << " " << vars.sysID << " " << vars.majorVer << "." << vars.minorVer << " rev " << vars.rev << endl;
		excom.expanVer();
	}
	else {
		cout << vars.lt << vars.pt << vars.usrin << " does not appear to be a valid command. Type \'help' to get help. " << endl;

	}

	//clearing all local arrays and vars
	fill_n(localUsrIn1, 2, 0);//clears int varable and fills with zeros
	fill_n(localUsrIn2, 2, "");//clears string varable and fills with nothing
}