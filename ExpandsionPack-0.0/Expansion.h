#pragma once

#ifdef MATHLIBRARY_EXPORTS  
#define EXPANSION __declspec(dllexport)   
#else  
#define EXPANSION __declspec(dllimport)   
#endif  
//before everything you must use EXPANSION
namespace ExpansionPack {
	class excommands {
	public:
		static EXPANSION void expanVer();
	};
}