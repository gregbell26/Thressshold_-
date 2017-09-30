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
/*
0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE
*/
void systemFunctions::color(int back, int text) {
	if (back > 15 || text > 15) {
		cout << vars.lt << vars.pt << "Invalid color code" << endl;
		cout << vars.lt << vars.pt << "The color codes are BACKGROUND COLORS " <<
			"0 BLACK | " <<
			"TEXT COLORS " <<
			"1 BLUE | " <<
			"2 GREEN | " <<
			"3 CYAN | " <<
			"4 RED  | " <<
			"5 MAGENTA | " <<
			"6 BROWN | " <<
			"7 LIGHTGRAY | " <<
			"8 DARKGRAY | " <<
			"9 LIGHTBLUE | " <<
			"10 LIGHTGREEN | " <<
			"11 LIGHTCYAN | " <<
			"12 LIGHTRED | " <<
			"13 LIGHTMAGENTA | " <<
			"14 YELLOW | " <<
			"15 WHITE " <<
			endl;
		cout << vars.lt << vars.pt << "\"color <backgound-color-code> <text-color-code>\"" << endl;
	}
	else {
		sFuncts.clrscrn();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back | text);
		sFuncts.clrscrn();
		sFuncts.gui();

	}
	
}