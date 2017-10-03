#pragma once
#include <string>
#ifdef MATHLIBRARY_EXPORTS  
#define EXPANSION __declspec(dllexport)   
#else  
#define EXPANSION __declspec(dllimport)   
#endif  
//before everything you must use EXPANSION
using namespace std;
namespace ExpansionPack {
	class excommands {
	public:
		static EXPANSION void expanVer();
		static EXPANSION int commandHandler(string userInput);
	};
}

