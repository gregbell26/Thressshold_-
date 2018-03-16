#pragma once
#include <iostream>
#include <string>

class ExProgram {
private:
	std::string programName;

	int programVer;

	std::string programPublisher;

public:
	ExProgram();

	void setProgramName(std::string name);

	void getMetadata();

	int getProgramVer();

	std::string getProgramPublisher();

	void launch();

	bool locate();

	~ExProgram();
};

ExProgram exP;

