#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
//#include "variables.h"
#include "systemFunctions.h"
//#include "bootAnimation.h"
//#include "userFunctions.h"
//#include "debugConsole.h"


void systemFunctions::clrscrn() {//I did not write most of this. But I know How it works, It NEEDS to have windows.h to work correctly
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;//to find the current cell amount 
	COORD                      homeCoords = { 0, 0 };// just the corrnets that the curor will be placed at 

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;


	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;


	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;


	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;


	SetConsoleCursorPosition(hStdOut, homeCoords);






}
