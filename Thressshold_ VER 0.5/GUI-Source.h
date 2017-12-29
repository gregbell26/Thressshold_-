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



int systemFunctions::gui() { // this is 100% my code!!! It works to a certain extent. 
	sFuncts.screenResFinder();
	sFuncts.clrscrn();
	sFuncts.clrscrn();

	sFuncts.clrscrn();
	HANDLE                     hStdOut;
	COORD                      set1 = { 2, 2 };//second line
	COORD                      set2 = { 2, 1 };//Ver info
	COORD                      set3 = { 0, 4 };//User input
	COORD                      set4 = { 0, 2 };//cornor for second line
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return 0;
	//top cornor 
	cout << endl << (char)219 << (char)219;
	while (vars.cols > 2) {
		cout << "=";
		vars.cols -= 1;
	}

	while (vars.rows > 3) {
		cout << "|" << "|" << endl;
		vars.rows -= 1;
	}
	sFuncts.screenResFinder();
	cout << (char)219 << (char)219;
	while (vars.cols > 2) {
		cout << "=";
		vars.cols -= 1;
	}
	
	SetConsoleCursorPosition(hStdOut, set1);
	sFuncts.screenResFinder();
	//second line
	while (vars.cols > 2) {
		cout << "=";
		vars.cols -= 1;
	}
	SetConsoleCursorPosition(hStdOut, set2);
	//Ver Info
	cout << "\t\t\t\t\t"; //setting location
	cout << pname << " Release " << vars.MAJOR_VER << "." << vars.MINOR_VER << "." << vars.BUG_FIX << " rev " << vars.REV_CHAR;
	SetConsoleCursorPosition(hStdOut, set4);
	cout << (char)219 << (char)219;
	//start of user input
	SetConsoleCursorPosition(hStdOut, set3);
	//Making system active
	


	return(1);


}