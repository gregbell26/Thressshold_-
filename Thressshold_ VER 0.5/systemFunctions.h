#pragma once
#include <iostream>
#include <string>



using namespace std;



class systemFunctions {
public:
	void screenResFinder();

	void clrscrn();

	int gui();

	int bootLogo();

	void killTOS();

	int restartTOS();

	void commandHandler(string usrIn);
	
	void color(int text, int back);

};


static systemFunctions sFuncts;//we should be using external vars so I don't have to inlcude the master variable everytime. But it throws a shit ton of errors. So... yeah