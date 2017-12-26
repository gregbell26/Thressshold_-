#include "SystemFunctsUser.h"


using namespace SystemFuncts;
SystemFunctsUser::SystemFunctsUser(){
	cols = 0;
	rows = 0;

	//VER 5.0.3 REV B
	MAJOR_VER = 5;
	MINOR_VER = 0;
	BUG_FIX = 3;
	REV_CHAR = 'B';

}

void SystemFunctsUser::clrscrn() {
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

void SystemFunctsUser::screenResFinder() {

	CONSOLE_SCREEN_BUFFER_INFO csbi;


	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	SMALL_RECT rect;
	COORD coord;
	coord.X = cols; // Defining our X and
	coord.Y = rows;  // Y size for buffer.

	rect.Top = 0;//orgin point x
	rect.Left = 0;//orgin point y
	rect.Bottom = coord.Y - 1; // end point x
	rect.Right = coord.X - 1;  // end point y

	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
	SetConsoleScreenBufferSize(hwnd, coord);       // set buffer size and that removes scroll bar
	SetConsoleWindowInfo(hwnd, TRUE, &rect);       // set window size
}

int SystemFunctsUser::drawGUI() {
	screenResFinder();
	clrscrn();
	clrscrn();

	clrscrn();
	HANDLE                     hStdOut;
	COORD                      set1 = { 2, 2 };//second line
	COORD                      set2 = { 2, 1 };//Ver info
	COORD                      set3 = { 0, 4 };//User input
	COORD                      set4 = { 0, 2 };//cornor for second line
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return 0;
	//top cornor 
	cout << endl << (char)219 << (char)219;
	while (cols > 2) {
		cout << "=";
		cols -= 1;
	}

	while (rows > 3) {
		cout << "|" << "|" << endl;
		rows -= 1;
	}
	screenResFinder();
	cout << (char)219 << (char)219;
	while (cols > 2) {
		cout << "=";
		cols -= 1;
	}

	SetConsoleCursorPosition(hStdOut, set1);
	screenResFinder();
	//second line
	while (cols > 2) {
		cout << "=";
		cols -= 1;
	}
	SetConsoleCursorPosition(hStdOut, set2);
	//Ver Info
	cout << "\t\t\t\t\t"; //setting location
	cout << pname << " Release " << MAJOR_VER << "." << MINOR_VER << "." << BUG_FIX << " rev " << REV_CHAR;
	SetConsoleCursorPosition(hStdOut, set4);
	cout << (char)219 << (char)219;
	//start of user input
	SetConsoleCursorPosition(hStdOut, set3);
	//Making system active



	return(1);

}

int SystemFunctsUser::bootLogo() {
	char t = (char)219; //localy defined variables so I dont have to type (char)219 every FUCKING TIME
	char s = ' ';//same as above
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t" << t << t << t << t << t << t << t << t << t << t << t << t << "     "; cout << t << t << t << t << t << t << t << t << s << s << s << "      "; cout << t << t << t << t << t << t << t << t << t << t << t << t << t << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << s << s << s << s << t << t << s << s << s << s << "     "; cout << t << t << t << t << t << t << t << t << s << s << s << s << s << "     "; cout << t << t << t << t << t << t << t << t << s << s << s << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << t << t << s << s << "      "; cout << s << s << s << s << s << s << t << t << s << s << s << s << s << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << s << s << t << t << s << s << t << t << s << s << "     "; cout << t << t << s << s << s << s << s << t << t << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << t << t << s << s << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << s << t << t << s << "      "; cout << s << s << s << s << s << s << t << t << s << s << s << s << s << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << s << s << s << "     "; cout << t << t << s << s << s << s << s << s << t << t << s << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << s << t << t << s << "      "; cout << s << s << s << s << s << s << t << t << s << s << s << s << s << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << s << s << s << "     "; cout << t << t << s << s << s << s << s << s << s << t << t << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << t << t << s << s << "      "; cout << s << s << s << s << s << s << t << t << s << s << s << s << s << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << t << t << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << s << s << t << t << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << t << t << t << t << t << t << s << s << s << "      "; cout << s << s << s << s << s << s << t << t << s << s << s << s << s << "      "; cout << t << t << t << "     "; cout << t << t << t << t << t << t << t << t << t << t << t << t << "     "; cout << t << t << s << t << t << t << t << s << t << t << "     "; cout << t << t << t << t << t << t << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << s << s << t << t << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << t << t << s << s << s << s << s << "      "; cout << s << s << s << s << s << s << t << t << s << s << s << s << s << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << t << t << s << s << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << s << t << t << s << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << t << t << s << s << s << s << "      "; cout << s << s << s << s << s << s << t << t << s << s << s << s << s << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << t << t << s << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << t << t << s << s << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << t << t << s << s << s << "      "; cout << s << s << s << s << s << s << t << t << s << s << s << s << s << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << t << t << s << s << s << "     " << endl;
	cout << "\t\t\t" << s << s << s << s << s << t << t << s << s << s << s << s << "     "; cout << t << t << s << s << s << s << s << t << t << s << s << "      "; cout << t << t << t << t << t << t << t << t << t << t << t << t << t << "      "; cout << t << t << t << "     "; cout << t << t << s << s << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << s << t << t << "     "; cout << t << t << s << s << s << s << s << t << t << s << s << s << s << "     "; cout << t << t << t << t << t << t << t << s << s << s << s << "     " << endl;
	return 0;
}

void SystemFunctsUser::shutdown() {
	clrscrn();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),//sets console colors The colors are stored in vars.h
		15
	);
	clrscrn();
	clrscrn();
	clrscrn();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),//sets console colors The colors are stored in vars.h
		15
	);
	drawGUI();
	clrscrn();
	clrscrn();
	clrscrn();
	bootLogo();
	cout << "Exiting";
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";

	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";
	Sleep(10);
	cout << ".";

	exit(1);


}



SystemFunctsUser::~SystemFunctsUser()
{
}
