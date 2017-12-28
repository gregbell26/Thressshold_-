#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <filesystem>
#include "variables.h"
#include "systemFunctions.h"
#include "bootAnimation.h"
#include "userFunctions.h"
#include "debugConsole.h"
/*
*This is a mess. 
*
*/
namespace fs = std::experimental::filesystem;
using namespace std;

//using namespace fs;
double findDirSize(fs::path path) {
	const int KILOBYTES = 1024;
	double totalSize = 0;
	for (auto & fileName : fs::directory_iterator(path)) {
		totalSize += fs::file_size(fileName);//adds bytes
	}
	return totalSize/KILOBYTES;//converts to kb
}
int debugConsole(){	
	fs::path fileDirectory;
	if (!dvars.devIn.compare("user")) {
		fileDirectory =  "../User-Source";
		cout << vars.lt << vars.pt << "Loading User module..." << endl;
		cout << vars.lt << vars.pt << "Total Size: " << findDirSize(fileDirectory) << "kb" << endl;//working on finding a dynamic way to find total size
		cout << vars.lt << vars.pt << "Files: ";
		for (auto & fileName : fs::directory_iterator(fileDirectory)) {
			cout << fileName << ", ";
		}
		cout << endl;
		cout << vars.lt << vars.pt << "Load Complete." << endl;
		cout << vars.lt << vars.pt << "Listing all varables in user: (note: some of the variables are private so they will not be displayed without a getter method)" << endl;
		cout << vars.lt << vars.pt << "Active user (User.activeUser): " << User.getActiveUser() << endl;
		cout << vars.lt << vars.pt << "Active user password (User.activePassword): " << User.getActivePassword() << endl;
		cout << vars.lt << vars.pt << "Active user develeoper (User.userData[0]): " << User.isDev() << endl;
		cout << vars.lt << vars.pt << "Active user admin (User.userData[1]): " << User.isAdmin() << endl;
		cout << vars.lt << vars.pt << "Listing variables Done." << endl;


	}
	else if (!dvars.devIn.compare("activation")) {
		fileDirectory = "../Activation-Source";
		cout << vars.lt << vars.pt << "Loading Activation module..." << endl;
		cout << vars.lt << vars.pt << "Total Size: " << findDirSize(fileDirectory) << "kb" << endl;
		cout << vars.lt << vars.pt << "Files: ";
		for (auto & fileName : fs::directory_iterator(fileDirectory)) {
			cout << fileName << ", ";
		}
		cout << endl;
		cout << vars.lt << vars.pt << "Load Complete." << endl;
		cout << vars.lt << vars.pt << "Listing all varables in activation: (note: some of the variables are private so they will not be displayed without a getter method)" << endl;
		cout << vars.lt << vars.pt << "Active pruduct key (TOSAct.pKey): " << TOSAct.getPKey() << endl;
		cout << vars.lt << vars.pt << "Activated (TOSAct.isActive): " << TOSAct.checkIsActive() << endl;
		cout << vars.lt << vars.pt << "Developer mode avaiable (TOSAct.devModeAviable): " << TOSAct.getDevModeAviable() << endl;
		cout << vars.lt << vars.pt << "Listing variables Done." << endl;
	}
	else if (!dvars.devIn.compare("exit")) {
		dvars.devModeEnabled = false;
	}
	else {
		cout << vars.lt << vars.pt << "Bad module name" << endl;
	}
	return 0;
}