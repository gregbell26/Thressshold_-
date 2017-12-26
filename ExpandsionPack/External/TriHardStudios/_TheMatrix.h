#include <iostream>
#include <windows.h>
namespace _TheMatrix {


	int Modulus(int iN, int iMod) {
		int iQ = (iN / iMod);
		return iN - (iQ*iMod);
	}

	char GetChar(int iGenerator, char cBase, int iRange) {//gens a random charector
		return (cBase + Modulus(iGenerator, iRange));
	}

	int TheMatrix() {
		// Color code
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 2);
		//::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); // makes it full screen
		char caRow[80];
		int j = 7;
		int k = 2;
		int l = 5;
		int m = 1;
		std::cout << "Welcome to the Matrix" << std::endl;
		Sleep(1000);
		int i =0;
		while (i < 100) {
			cout << "\t";
			// Output a random row of characters
			for (int i = 0; i < 80; ++i)
			{
				
				if (caRow[i] != ' ') {
					caRow[i] = GetChar(j + i*i, 33, 30);
					if (((i*i + k) % 71) == 0) {
						SetConsoleTextAttribute(hConsole, 7);
					}
					else {
						SetConsoleTextAttribute(hConsole, 2);
					}
				}
				std::cout <<  caRow[i];
				SetConsoleTextAttribute(hConsole, 2);
			}
			j = (j + 31);
			k = (k + 17);
			l = (l + 47);
			m = (m + 67);
			caRow[Modulus(j, 80)] = '-';
			caRow[Modulus(k, 80)] = ' ';
			caRow[Modulus(l, 80)] = '-';
			caRow[Modulus(m, 80)] = ' ';
			// Delay between lines
			Sleep(10);
			i++;
		} //end while
		return 0;
	}
}