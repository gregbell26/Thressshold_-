#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include <windows.h>
#include <conio.h>
#include "variables.h"
#include "systemFunctions.h"

using namespace std;

ofstream fout;
int tosVer() {
	if (vars.majorVer < 1) {
		vars.beta = true;
		if (vars.beta == true) {
			vars.sysID = "Beta Developer Release";
		}
	}
	else {
		vars.sysID = "Thresshold_ Public Release";
	}
	fout << "INFORMATION: " << pname << " " << vars.sysID << " " << vars.majorVer << "." << vars.minorVer << " rev " << vars.rev << endl;
	return 0;
}

void firstRunChecker() {
	ifstream fin("TOSUsrInfo.tos");

	if (fin.good()) {
		fout << "INFORMATION: User Data Found." << endl;
		vars.firstrun = false;
	}

	else {
		fout << "WARNING: No User Data Found, Thresshold_ is setting up firstrun" << endl;
		vars.firstrun = true;
	}
	fin.close();
}

void bootAnimation() {
	char w = char(219);
	fout.open("TOSStartUpLog.log");
	fout << "Thresshold_ Start Log" << endl;
	fout << "INFORMATION: Start up started at " << endl;
	sFuncts.clrscrn();
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); // Sets console size. (full screen)
	sFuncts.clrscrn();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),//sets console colors The colors are stored in vars.h
		defaultStartup
	);
	sFuncts.clrscrn();
	sFuncts.bootLogo();
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t";
	cout << w << w << w;//start of loading screen
	Sleep(100);
	firstRunChecker();
	cout << w << w << w << w << w << w << w << w << w << w;
	Sleep(100);
	sFuncts.screenResFinder(); //for some weird reason this removes the scroll bar
	cout << w << w << w << w << w << w;
	Sleep(100);
	tosVer();
	cout << w << w << w << w << w << w << w << w << w << w;
	vars.ready = true;
	Sleep(2500);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";


}