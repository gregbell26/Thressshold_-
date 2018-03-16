#include "Expansion.h"
#include "External\TriHardStudios\_TheMatrix.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;


namespace ExpansionPack {
	void excommands::expanVer() {
		cout << "Thresshold_ Expansion Pack Version 0.1.4" << endl;
	}

	bool excommands::commandHandler(string userInput, bool aviable) {
		//userInput = "matrix";
		if (aviable) {

			if (!userInput.compare("matrix")) {
				Sleep(10);
				cout << '|' << char(219) << "The Matrix" << endl;
				Sleep(10);
				cout << '|' << char(219) << "TriHard Studios" << endl;
				Sleep(10);
				cout << '|' << char(219) << "Version 1.0" << endl;
				Sleep(10);
				cout << '|' << char(219) << "Loading...\n\n\n\n\n\n\n\n\n\n\n" << endl;
				Sleep(100);
				_TheMatrix::TheMatrix();

				return true;

			}

			else {
				return false;
			}
		}
		else {
			return false;
		}
		
	}
}
