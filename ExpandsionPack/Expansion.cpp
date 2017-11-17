#include "Expansion.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

//start of funtsion defiations
typedef int(_stdcall *EXFUNCTIONmartixRun)();//this is creating a function pointer to the DLL you can add more for each DLL you use. Just put EXFUNCTION first 
//end of function definations

HINSTANCE exFunctLibLoad;//this is the thing we use to load the funtion
namespace ExpansionPack {
	void excommands::expanVer() {
		cout << "Thresshold_ Expansion Pack Version 0.0.0.0.0.0.1" << endl;
	}

	int excommands::commandHandler(string userInput) {
		userInput = "matrix";
		
		if (!userInput.compare("matrix")) {
			cout << "Entered If statemnt" << endl;
			cin.get();
			cin.get();
			EXFUNCTIONmartixRun FunctAddress;//this is making the pointer from funtion pointer that we made before
			//try {
				exFunctLibLoad = LoadLibrary(L"External\\TriHardStudios\\Matrix.dll");
				cout << "Loaded Libary" << endl;
				cin.get();

				if (!exFunctLibLoad) {
					cout << '|' << char(219) << "Failed to load DLL" << endl;

				}
				else {
					cout << '|' << char(219) << "Loaded DLL.." << endl;
					cin.get();
					FunctAddress = (EXFUNCTIONmartixRun)GetProcAddress(exFunctLibLoad, "matrixRun");
					cout << "about to call function" << endl;
					cin.get();
					FunctAddress();
				}
			//}


		}

		else {
			cout << '|' << char(219) << userInput << " does not appear to be a valid command. Type \'help' to get help. " << endl;
		}
		return('\0');
	}
}
