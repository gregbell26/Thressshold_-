#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "variables.h"
#include "systemFunctions.h"
#include "bootAnimation.h"
#include "userFunctions.h"
#include "debugConsole.h"

int systemFunctions::restartTOS() {

	vars.ready = false;
	vars.sysActive = false;
	bootAnimation();
	return 0;

}