#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>

using namespace std;

const int DataSize = 144;

std::string IntToHex(int n) {
	std::stringstream ss;
	ss << std::hex << n;
	return ss.str();
}

int main() {
	unsigned char Memo[DataSize];
    
	for (int i = 0; i++; i < DataSize) { 
		Memo[i] = NULL; 
	}

	__asm {
		pushad

		//Ваш код на языке ассемблера 

		popad
	}

	for (int i = 0; i < DataSize; i++) {
		if ((i % 16) == 0) {
			cout << "\n" << setw(2) << i / 16 << ":";
		}
		else {
			cout << " " << setw(2) << IntToHex(Memo[i - 1]);
		}
	}

	_getch();
	return 0;
} 
