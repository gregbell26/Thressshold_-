#pragma once
#include "variables.h"
#include "userFunctions.h"
#include "systemFunctions.h"


int userFunctions::logout() {
	uvars.actUsr = "\0";
	uvars.actUsrPasswd = "\0";
	sFuncts.clrscrn();
	uFuncts.loginTOS();
	return 0;
}