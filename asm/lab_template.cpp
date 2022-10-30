#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>

const int DATA_SIZE = 144;

std::string intToHex(int n) {
	std::stringstream ss;
	ss << std::hex << n;
	return ss.str();
}

int main() {
	unsigned char data[DATA_SIZE];
    
	for (int i = 0; i < DATA_SIZE; i++) { 
		data[i] = 0; 
	}

	__asm {
		pushad

		//Ваш код на языке ассемблера 

		popad
	}

	for (int i = 0; i < DATA_SIZE; i++) {
		if ((i % 16) == 0) {
			std::cout << "\n" << setw(2) << i / 16 << ":";
		}
		else {
			cout << " " << setw(2) << intToHex(data[i - 1]);
		}
	}

	_getch();
	return 0;
} 
