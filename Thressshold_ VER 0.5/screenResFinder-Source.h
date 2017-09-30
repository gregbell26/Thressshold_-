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

void systemFunctions::screenResFinder() {//I didn't write this code. I combined things forom the net to make this. It needs windows.h to work

	CONSOLE_SCREEN_BUFFER_INFO csbi;


	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	vars.cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	vars.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	SMALL_RECT rect;
	COORD coord;
	coord.X = vars.cols; // Defining our X and
	coord.Y = vars.rows;  // Y size for buffer.

	rect.Top = 0;//orgin point x
	rect.Left = 0;//orgin point y
	rect.Bottom = coord.Y - 1; // end point x
	rect.Right = coord.X - 1;  // end point y

	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
	SetConsoleScreenBufferSize(hwnd, coord);       // set buffer size and that removes scroll bar
	SetConsoleWindowInfo(hwnd, TRUE, &rect);       // set window size





}