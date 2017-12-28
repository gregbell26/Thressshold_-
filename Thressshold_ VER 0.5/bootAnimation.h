#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "INCLUDE.h"
#include <windows.h>
#include <conio.h>
#include "variables.h"
#include "systemFunctions.h"
#include "User-Source\User.h"
#include "Activation-Source\Activation.h"
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
void activationChecker() {
	if (TOSAct.checkIsActive()) {
		fout << "INFORMATION: Activation data found." << endl;
		fout << "INFORMATION: Product key valid." << endl;
	}

	else {
		fout << "WARNING: Activation data not found or invalid." << endl;
	}
}
void firstRunChecker() {

	if (User.firstRunVar) {
		fout << "WARNING: No User Data Found, Thresshold_ is setting up firstrun" << endl;

	}

	else {
		fout << "INFORMATION: User Data Found." << endl;
		

	}
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
	activationChecker();
	cout << w << w << w << w << w << w << w << w << w << w;
	Sleep(100);
	sFuncts.screenResFinder(); 
	cout << w << w << w << w << w << w;
	Sleep(100);
	tosVer();
	cout << w << w << w << w << w << w << w << w << w << w;
	vars.ready = true;
	Sleep(2500);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";


}