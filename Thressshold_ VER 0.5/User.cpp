#include "User.h"
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "variables.h"
#include "systemFunctions.h"
using namespace Users;
using namespace std;


/*
The default construtor will load the available users into memory
Check if they exist
if not then it will set a variable to true and then call first run
if so it will set a variable to false then send you to the login page 

This should contain a firstrun(), logon(), and logoff()



*/


User::User() {//construtor
	ifstream fin;
	//userData.resize(5);
	fin.open(".\\Users\\Users.ths");
	if (fin.good()) {
		firstRunVar = false;



	}
	else {
		firstRunVar = true;
	}



}

string User::toOutput(std::string oldName) {
	string output = oldName + ".usrData";

	return output;

}

std::string Users::User::getActiveUser()
{
	return activeUser;
}

std::string Users::User::getActivePassword()
{
	return activePassword;
}

int User::firstRun() {
	if (firstRunVar || vars.newUser) {
		sFuncts.clrscrn();//clears screen
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), loginColors);//sets colors
		sFuncts.clrscrn();//clears screen


						  //local varables
		ofstream fout;//command to output to a file
		string tempUsrName = "";//so we can store the user's name for the user data generation
		char ch;
		char usrInYN = '\0';// \0 is null
		bool passMatch = false;
		string temp;
		string usrin;
		//end of local var defination

		CreateDirectory(L"Users", NULL);//Creating the subfolder for user stuff
		SetCurrentDirectory(L"Users");//seting the current dir
									  //opening user info file
		fout.open("Users.ths", ios::app /*| ios::binary*/);//.ths will be file extendsion for this program Also ios app places the writer at the end of the file. 
		while (firstRunVar || vars.newUser) {
			//fill_n(uvars.usrSettings, 5, 0);//clears the user setting array
			userData.erase(userData.begin(), userData.end());//clears user data

			sFuncts.gui();
			cout << vars.lt << vars.pt << " Hello! Welcome to Thresshold_" << endl;
			cout << vars.lt << vars.pt << " Please enter the user name you'd like to use: ";
			cin >> temp;//inputs user name in temp
			fout << temp << endl;
			tempUsrName = temp;//stores user name 
			temp = "";
			fout.flush();//writes to file
			cout << vars.lt << vars.pt << " User name written to file successfully" << endl;
			cout << vars.lt << vars.pt << " Please enter the password you'd like to use: ";
			ch = _getch();
			while (ch != 13) {
				temp.push_back(ch);// inputs password in to temp
				cout << "*";
				ch = _getch();
			}
			cout << endl;
			while (!passMatch) {
				cout << vars.lt << vars.pt << " Please enter your password again: ";
				ch = _getch();
				while (ch != 13) {
					usrin.push_back(ch);// inputs password in to usrin to we can check if matches the other password
					cout << "*";
					ch = _getch();
				}
				cout << endl;
				if (!temp.compare(usrin)) {
					passMatch = true;
				}
				else {
					cout << vars.lt << vars.pt << " Your password did not match. Lets try again" << endl;
				}
				usrin = "";
			}
			cout << vars.lt << vars.pt << " Passwords match. Writing to file.." << endl;
			fout << temp;
			fout.flush();


			cout << vars.lt << vars.pt << " Password written to file successfully" << endl;
			Sleep(100);
			cout << vars.lt << vars.pt << " Closing File....." << endl;
			fout << endl;
			fout.close();
			cout << vars.lt << vars.pt << " Begining Generation of User Data File..." << endl << endl;

			fout.open(toOutput(tempUsrName));//this will create a user data file with the users name 
			cout << vars.lt << vars.pt << " Is this a developer account? (y/n): ";
			cin >> usrInYN;
			if (usrInYN == 'y' || usrInYN == 'Y') {
				userData.push_back(1);
			}
			usrInYN = '\0';
			cout << endl;
			cout << vars.lt << vars.pt << " Should this account be admin? (y/n): ";
			cin >> usrInYN;
			if (usrInYN == 'y' || usrInYN == 'Y') {
				userData.push_back(1);
			}
			usrInYN = '\0';
			cout << endl;
			cout << vars.lt << vars.pt << " Writting user data to file..." << endl;
			for (int i = 0; i < userData.size(); i++) {
				fout << userData[i];
				fout << endl;
			}
			fout.close();
			cout << vars.lt << vars.pt << " Ending User Generation" << endl;
			firstRunVar = false;
			vars.newUser = false;
			vars.ready = true;
			Sleep(100);

			/*cout << vars.lt << vars.pt << "Resarting........" << endl;
			Sleep(1000);
			sFuncts.restartTOS();*/

		}
	}


	return 0;
}

void User::logOn() {
	
		//int av = 5;//locally defined variable for the max amount of users and passwords
		bool loginS = false;
		int loginA = 0;
		bool userMatch, passMatch;
		ifstream fin;//file input 
					 //ofstream fout;//fie output
		string tempUsr;
		string tempPass;
		string usrIn, temp;
		char ch;
		//eof local defination

		//loading users into memory
		SetCurrentDirectory(L"Users");
		fin.open("Users.ths");
		while (fin >> tempUsr) {
			fin >> tempPass;

			aviUsers.push_back(tempUsr);
			aviPasswords.push_back(tempPass);

			tempUsr = "\0";
			tempPass = "\0";
		}
		
		fin.close();
		sFuncts.gui();

		while (loginS == false && loginA <= 5) {
			cout << endl;
			cout << vars.lt << vars.pt << "Please Login" << endl;
			cout << vars.lt << vars.pt << "Enter User Name: ";
			cin >> usrIn;
			cout << endl;
			cout << vars.lt << vars.pt << "Enter Password for the User " << usrIn << ": ";
			//cin >> temp;
			ch = _getch();
			while (ch != 13) {
				temp.push_back(ch);// inputs password in to temp
				cout << "*";
				ch = _getch();
			}
			cout << endl;
			cout << vars.lt << vars.pt << "Checking User Info... ";
			for (int i = 0; i < aviUsers.size(); i++) {
				if (!aviUsers[i].compare(usrIn)) {
					userMatch = true;
					break;
				}
				else {
					userMatch = false;
				}
			}
			if (userMatch) {
				cout << " | User Name - Valid ";
				for (int i = 0; i < aviPasswords.size(); i++) {
					if (!aviPasswords[i].compare(temp)) {
						passMatch = true;
						break;
					}

					else {
						passMatch = false;
					}
				}
				if (passMatch) {
					cout << " | Password - Valid" << endl;
					cout << vars.lt << vars.pt << "Welcome to Thresshold_ " << endl;
					activeUser = usrIn;

					usrIn = "";//clar userin var
					activePassword = temp;
					temp = "";//clear temp var
					loginS = true;
					vars.sysActive = true;

				}
				else {
					temp = "";
					cout << " | Password - Invaild | Login Failed";
					loginA++;
				}
			}
			else {
				temp = "";
				cout << " | User Name - Invaild | Login Failed";
				loginA++;
			}


		}
		if (loginS == true) {

			fin.open(toOutput(activeUser));//open the now active user's data file
								   //cin.get();//debug
			if (fin.good()) {
				cout << vars.lt << vars.pt << "User Data File Found" << endl;//if we find the file and it is not curruted load the data from it 
				int tempData;
				while (fin >> tempData) {
					userData.push_back(tempData);
				}

			}
			else {
				cout << vars.lt << vars.pt << "We could not find that user's data file. Login Halted. " << endl;
				cout << vars.lt << vars.pt << "Press any key to quit Thresshold_" << endl;
				cin.get();
				sFuncts.killTOS();
			}

		}

		else if (loginA > 5) {
			sFuncts.killTOS();
		}

		//Sleep(500);//debug


}

void User::logOff() {
	activeUser = "\0";
	activePassword = "\0";
	sFuncts.clrscrn();
	logOn();
}

bool Users::User::isDev() {
	if (userData[1] == 1) 
		return true;
	

	else
		return false;
}

bool Users::User::isAdmin() {
	if (userData[2] == 1)
		return true;
	else
		return false;
}


User::~User() {




}
