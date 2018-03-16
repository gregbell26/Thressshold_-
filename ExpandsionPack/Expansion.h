#pragma once
#include <string>
#ifdef MATHLIBRARY_EXPORTS  
#define EXPANSION __declspec(dllexport)   
#else  
#define EXPANSION __declspec(dllimport)   
#endif  
//before everything you must use EXPANSION
using namespace std;
namespace ExpansionPack {//any functions you add here will not have an impact on the funcaity of this program.
	class excommands {
	public:
		static EXPANSION void expanVer();//This has to be kept and updated perotically
		static EXPANSION bool commandHandler(string userInput, bool avaible);//so does this but feel free to edit it in the cpp file
	};
}

