#include "Expansion.h"
#include <MatrixDLL.h>//this is a dll
#include <iostream>
#include <string>
using namespace std;

Matrix::Matrix matrix;//class defination. the first thing is the namespace then the next thing is the class name

namespace ExpansionPack {
	void excommands::expanVer() {
		cout << "Thresshold_ Expansion Pack Version 1.0" << endl;
	}

	int excommands::commandHandler(string userInput) {
		if (!userInput.compare("Matrix")) {
			matrix.matrixRun();
		}
		else {
			cout << '|' << char(219) << userInput << " does not appear to be a valid command. Type \'help' to get help. " << endl;
		}
		return('\0');
	}
}
