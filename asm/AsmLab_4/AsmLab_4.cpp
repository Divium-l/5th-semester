#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <bitset>

std::string intToHex(int n) {
	std::stringstream ss;
	ss << std::hex << std::uppercase << n;
	return ss.str();
}

int main() {
	
	//uint32_t number = 0x47AC'2EFA;
	uint32_t number = 0xFFFFFFFF;
	
	uint8_t zeroes_1 = 0;
	uint8_t ones_1 = 0;
	uint8_t zeroes_2 = 0;
	uint8_t ones_2 = 0;

	__asm {
		pushad

		LEA EBX, number
		MOV EAX, [EBX]

		// AL - lower byte

		popad
	}

	std::cout << "number: 0xb" << std::bitset<32>(number) << " | "  << "0x" << intToHex(number) << " | " << number << std::endl;
	std::cout << std::setw(23) << "1.1 number of zeroes: " << zeroes_1 << std::endl;
	std::cout << std::setw(23) << "1.1 number of ones: " << ones_1 << std::endl;
	std::cout << std::setw(23) << "1.2 number of zeroes: " << zeroes_2 << std::endl;
	std::cout << std::setw(23) << "1.2 number of ones: " << ones_2 << std::endl;
	std::cout << std::endl;

	_getch();
	return 0;
}
