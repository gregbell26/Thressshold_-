#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <filesystem>
namespace Actiavtion {
	class TOSActivation {
	private:

		const std::string coreKey = "TOS-WM2016-WMCO";
		const std::string fullKey = "TOS-LW2016-LWFL";
		//const std::string ofKey = "TOS-OW2016-OWOL";
		const std::string devKey = "TOS-LW2016-WDEV";
		//const std::string winKey = "TOS-WM2016-WMWN";
		
		bool devModeAviable;
		bool isActive;
		bool expandPackAviable;
		std::string pKey;

	public:
		TOSActivation();
		
		bool checkIsActive();

		bool getDevModeAviable();

		bool getExpandPackAviable();

		std::string getPKey();

		void setPKey();




	};
}
static Actiavtion::TOSActivation TOSAct;