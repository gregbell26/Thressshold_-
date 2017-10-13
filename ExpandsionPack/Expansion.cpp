#include "Expansion.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;


namespace ExpansionPack {
	void excommands::expanVer() {
		cout << "Thresshold_ Expansion Pack Version 1.0" << endl;
	}

	int excommands::commandHandler(string userInput) {
		if (!userInput.compare("matrix")) {
			typedef int(*EXFUNCTIONmartixRun)();//this is creating a function pointer to the DLL
			HINSTANCE DLLLOAD = LoadLibrary("TheMatrixDLL.dll");


		}

		else {
			cout << '|' << char(219) << userInput << " does not appear to be a valid command. Type \'help' to get help. " << endl;
		}
		return('\0');
	}
}
