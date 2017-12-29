#include "./Activation.h"

using namespace std;
namespace fs = std::experimental::filesystem;
//ofstream fout;
//ifstream fin;

Actiavtion::TOSActivation::TOSActivation() {
	devModeAviable = false;
	isActive = false;
	pKey = "DEFAULT";


}

bool Actiavtion::TOSActivation::checkIsActive() {
	ifstream fin;
	SetCurrentDirectory(L"SYS");
	fin.open("TOS-ACT.ths");
	//fin >> pKey;
	if (fin.good()) {
		fin >> pKey;
		if (!pKey.compare(coreKey) || !pKey.compare(fullKey)) {
			isActive = true;
			SetCurrentDirectory(_T(".."));
		}
		else if (!pKey.compare(devKey)) {
			devModeAviable = true;
			isActive = true;
			SetCurrentDirectory(_T(".."));
		}
		
		else {
			isActive = false;
			SetCurrentDirectory(_T(".."));
		}
	}
	else {
		fs::path oldPath = fs::current_path();
		SetCurrentDirectory(_T(".."));
		if (!fs::exists("SYS"))
			fs::current_path(oldPath);
		isActive = false;
		
	}
	fin.close();
	
	return isActive;

}

bool Actiavtion::TOSActivation::getDevModeAviable(){
	return devModeAviable;
}

std::string Actiavtion::TOSActivation::getPKey() {
	return pKey;
}

void Actiavtion::TOSActivation::setPKey() {
	ofstream fout;
	if (!fs::exists("SYS")) {
		fs::create_directory("SYS");
		//cout << "CREATED ACTIVATION FOLDER" << endl;
	}//Creating the subfolder for system stuff.. if it doesn't exist
	fs::current_path("SYS");//sets dir
	fout.open("TOS-ACT.ths");
	cout << '|' << char(219) << "Please enter a valid Thresshold_ product key" << endl;
	cout << '|' << char(219) << "Or you can type exit to exit Thresshold_" << endl;
	cout << '|' << char(219) << "Key in: ";
	cin >> pKey;
	if (!pKey.compare("exit") || !pKey.compare("Exit"))
		exit(0);
	else
		fout << pKey;
	fout.close();
	fs::current_path("..");

}
