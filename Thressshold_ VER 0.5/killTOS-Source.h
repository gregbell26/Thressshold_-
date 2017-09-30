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

using namespace std;

void systemFunctions::killTOS(){
	sFuncts.clrscrn();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),//sets console colors The colors are stored in vars.h
		exitColors
	);
	sFuncts.clrscrn();
	sFuncts.clrscrn();
	sFuncts.clrscrn();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),//sets console colors The colors are stored in vars.h
		exitColors
	);
	sFuncts.gui();
	sFuncts.clrscrn();
	sFuncts.clrscrn();
	sFuncts.clrscrn();
	sFuncts.bootLogo();
	cout << "Exiting";
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";
	vars.ready = false;
	Sleep(10);
	cout << ".";
	
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";
	vars.sysActive = false;//these will allow us to exit the while loop. 
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";

	exit(1);

}
