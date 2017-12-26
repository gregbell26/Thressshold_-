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



int main(void) {
	

	//local vars
	string usrIn;
	//eof local vars

	bootAnimation();

	//vars.firstrun = true;s
	//vars.ready = true;
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
			while (vars.sysActive) {
				cout << vars.lt << vars.pt  << User.getActiveUser() <<  "@Thresshold_~";
				cin >> usrIn;
				cout << endl;
				sFuncts.commandHandler(usrIn);
				usrIn = "";
			}

		cout << pname << " failed to start or didn't activate" << endl;
		Sleep(1500);
		sFuncts.killTOS();

	//cin.get();//for debug purposes.. 
}