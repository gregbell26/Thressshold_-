#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#define pname "Thresshold_"

using namespace std;

namespace SystemFuncts {
	class SystemFunctsUser {
	private:
		int cols;// = 0;
		int rows;// = 0;
			 //Version info
		int MAJOR_VER;// = 0;
		int MINOR_VER;// = 6;
		int BUG_FIX;// = 5;
		char REV_CHAR;// = 'B';
	public:
		SystemFunctsUser();


		void clrscrn();

		void screenResFinder();

		int drawGUI();

		int bootLogo();

		void shutdown();

		~SystemFunctsUser();
	};
}


