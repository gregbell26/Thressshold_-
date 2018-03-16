#include "INCLUDE.h"


/*
Current issues:
we are using one master class.. WTF lets fix that. 
Possaiable fixes:




*/


/*int main() {// this is debug only... Don't mess with it this is just to generate the sussful start up log and becuase this uses  
	bootAnimation();
}
*/ 


namespace fs = std::experimental::filesystem;

int main(void) {
	//TCHAR resetDir[1024] = {};

	//local vars
	string usrIn;
	//int linesFilled =0;
	//eof local vars

	bootAnimation();
	//string root = fs::current_path();

	//vars.firstrun = true;s
	//vars.ready = true;
	sFuncts.clrscrn();
	sFuncts.gui();
	while (!TOSAct.checkIsActive())	{
		TOSAct.setPKey();
		cout << endl;

	}
	
	//SetCurrentDirectory(_T(".."));
	
		if (User.firstRunVar) {

			User.firstRun();
			sFuncts.clrscrn();
		}

			sFuncts.clrscrn();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				defaultMain);
			sFuncts.clrscrn();
			User.logOn();
			sFuncts.clrscrn();
			sFuncts.clrscrn();
			sFuncts.gui();
			sFuncts.screenResFinder();
			while (vars.sysActive) {
				cout << vars.lt << vars.pt  << User.getActiveUser() <<  "@Thresshold_" << fs::current_path()<<"/~";
				//linesFilled += 3;
				cin >> usrIn;
				cout << endl;
				/*if (linesFilled >= vars.cols - 3)
					sFuncts.clrscrn();*/
				sFuncts.commandHandler(usrIn);
				usrIn = "";
			}

		cout << pname << " failed to start or didn't activate" << endl;
		
		Sleep(1500);
		sFuncts.killTOS();

	//cin.get();//for debug purposes.. 
}