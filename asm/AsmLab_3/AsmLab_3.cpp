#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <random>

const int DATA_SIZE = 512;
const uint16_t MIN = 0x0;
const uint16_t MAX = 0xFFFF;

uint16_t random() {
	std::random_device rd;     
	std::mt19937 rng(rd());    
	std::uniform_int_distribution<uint16_t> uni(MIN, MAX);

	return uni(rng);
}

int main() {
	uint16_t arr[DATA_SIZE];

	for (int i = 0; i < DATA_SIZE; i++) {
		arr[i] = 0;
	}

	srand(time(0));

	__asm {
		pushad

		// EDI - счётчик нечётных
		// ESI - счётчик чётных
		// ECX - счётчик чисел, >= 50_000
		// EBX - счётчик чисел, < 10_000
		LEA EDI, arr

		MOV ESI, EDI
		ADD ESI, 256

		MOV ECX, ESI
		ADD ECX, 256

		MOV EBX, ECX
		ADD EBX, 256
	loop_start:
		// EAX = random()
		PUSH ECX
		CALL random
		MOVZX EAX, AX
		PUSH EAX
		// if (a % 2 == 0)
		CDQ
		MOV ECX, 2
		DIV ECX
		CMP EDX, 0
		POP EAX
		POP ECX
		JNZ is_even
		JMP is_odd
	is_even:
		MOV [ESI], EAX
		ADD ESI, 2
		JMP even_odd_exit
	is_odd:
		MOV [EDI], EAX
		ADD EDI, 2
		JMP even_odd_exit
	even_odd_exit:

		// if (a >= 50_000)
		CMP EAX, 50000
		JGE greater
		// if (a < 10_000)
		CMP EAX, 10000
		JL less
		JMP greater_less_exit
	greater:
		MOV [ECX], EAX
		ADD ECX, 2
		JMP greater_less_exit
	less:
		MOV [EBX], EAX
		ADD EBX, 2
		JMP greater_less_exit
	greater_less_exit:

		LEA EAX, arr
		ADD EAX, 256
		CMP EDI, EAX
		JGE loop_exit
		
		ADD EAX, 256
		CMP ESI, EAX
		JGE loop_exit

		ADD EAX, 256
		CMP ECX, EAX
		JGE loop_exit

		ADD EAX, 256
		CMP EBX, EAX
		JGE loop_exit
		JMP loop_start
	loop_exit:

		popad
	}

	for (int i = 0; i < DATA_SIZE; i++) {
		if ((i % 128) == 0) {
			std::string groupName;
			switch (i / 128) {
				case 0:
					groupName = "even";
					break;
				case 1:
					groupName = "odd";
					break;
				case 2:
					groupName = ">= 50_000";
					break;
				case 3:
					groupName = "< 10_000";
					break;
				default:
					groupName = "unknown condition";
			}
			std::cout << std::endl << std::setw(9) << groupName << ":";
		}
		else
			std::cout << " " << arr[i - 1];
	}

	_getch();
	return 0;
}
