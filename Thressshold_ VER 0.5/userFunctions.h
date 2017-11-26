#pragma once

using namespace std;

extern "C" {
	class userFunctions {
	public:
		int loginTOS();

		int firstRun();

		int logout();

	};
}


userFunctions uFuncts;

