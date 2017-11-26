#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
namespace Users {
	class User {
	private:
		int size_t = 5;
		//these are all the variables requieed to log on, use, and log off users
		std::vector<std::string> aviUsers;
		std::vector<std::string> aviPasswords;
		std::vector<int> userData;//default size 5 is defined in constor
		std::vector<int> userPrefences;
		std::string activeUser;
		std::string activePassword;


	public:
		bool firstRunVar = true;

		User(); 

		std::string toOutput(std::string oldName);

		std::string getActiveUser();//non critical 

		std::string getActivePassword();//non critical


		int firstRun();

		void logOn();

		void logOff();

		bool isDev();
		bool isAdmin();

		~User();
	};

}

static Users::User User;