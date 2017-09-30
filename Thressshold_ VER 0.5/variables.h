#pragma once
#include <string>

//this is used in everything... SO DON"T MESS WITH IT
#define pname "Tresshold_"
//colors
#define defaultStartup BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define loginColors BACKGROUND_GREEN| FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define defaultMain BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define exitColors  FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
using namespace std;
class sVariables {
public:
	bool ready = false;
	string usrin = "";
	bool sysActive = true;
	string temp = "";
	string excommands[5] = { "","","","","" };
	bool firstrun = true;
	//Version Info change accrodingly.
	int majorVer = 0;
	int minorVer = 4;
	char rev = 'A';
	bool beta = false;
	bool newUser = false;
	string sysID;
	int cols;
	int rows;
	char pt = (char)219; // for input stuff
	char lt = '|';// for intput stuff 
				  //lt MUST go before pt
				//These are to make sure that everything is spaced corectly 
	string curDir = "";
};

class aVariables {//don't use until STUFF :)
public:
	string coreKey = "TOS-WM2016-WMCO";
	string fullKey = "TOS-LW2016-LWFL";
	string ofKey = "TOS-OW2016-OWOL";
	string devKey = "TOS-LW2016-WDEV";
	string winKey = "TOS-WM2016-WMWN";
	bool isActive = false;
	string pKey = "stuff";

};

class dVariables {
public:
	bool devModeEnabled = false;
	string devIn = "";
};
class uVariables {
public:
	int usrSettings[5] = { 0,0,0,0,0 };
	string actUsrPasswd;
	string actUsr;
	string avaiableUsers[5] = { "","","","","" };
	string avaiablePasswords[5] = { "","","","","" };
};
aVariables avar;
dVariables dvars;
sVariables vars;
uVariables uvars;

