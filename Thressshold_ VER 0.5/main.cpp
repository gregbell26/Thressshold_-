#include "INCLUDE.h"


/*
Current issues:
new user is not working 
Possaiable fixes:
Who Knows Lets just pray!



*/


/*int main() {// this is debug only... Don't mess with it this is just to generate the sussful start up log and becuase this uses  
	bootAnimation();
}
*/ 



int main(void) {
	bootAnimation();
	//vars.firstrun = true;s
	//vars.ready = true;
	while (vars.ready = true) {
		if (vars.firstrun == true) {

			uFuncts.firstRun();
			sFuncts.clrscrn();
		}
		else if (vars.ready == true) {
			sFuncts.clrscrn();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				defaultMain);
			sFuncts.clrscrn();
			uFuncts.loginTOS();
			sFuncts.clrscrn();
			sFuncts.clrscrn();
			sFuncts.gui();
			while (vars.sysActive == true) {
				cout << vars.lt << vars.pt  << uvars.actUsr <<  "@Thresshold_~";
				cin >> vars.usrin;
				cout << endl;
				sFuncts.commandHandler();
				vars.usrin = "";
			}


		}
	}
		cout << pname << " failed to start or didn't activate" << endl;
		Sleep(1500);
		sFuncts.killTOS();

	//cin.get();//for debug purposes.. 
}