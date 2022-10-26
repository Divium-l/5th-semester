#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>

using namespace std;

const int DataSize = 512;

uint16_t random() {
	return 0xFFFF;
}

int main() {
	uint16_t Memo[DataSize];

	for (int i = 0; i < DataSize; i++) {
		Memo[i] = 0;
	}

	cout << &Memo << endl;

	srand(time(0));

	__asm {
		pushad

		// EDI - счётчик нечётных
		// ESI - счётчик чётных
		// EBX - счётчик чисел, >= 50_000
		// EDX - счётчик чисел, < 10_000
		LEA EDI, Memo

		MOV ESI, EDI
		ADD ESI, 256

		MOV EBP, ESI
		ADD EBP, 256

		MOV EDX, EBP
		ADD EDX, 256

		MOV ECX, 2

	loop_start:
		// if (a % 2 == 0)
		PUSH ECX
		CALL random
		POP ECX
		PUSH EAX
		CDQ
		MOV EBX, 2
		DIV EBX
		CMP EDX, 0
		JNZ is_even
		JMP is_odd
	is_even:
		POP EAX
		MOV [ESI], EAX
		ADD ESI, 2
		JMP even_odd_exit
	is_odd:
		POP EAX
		MOV [EDI], EAX
		ADD EDI, 2
		JMP even_odd_exit
	even_odd_exit:

		LOOP loop_start
		popad
	}

	for (int i = 0; i < DataSize; i++) {
		if ((i % 128) == 0) {
			cout << "\n" << i / 128 << ":";
		}
		else {
			cout << " " << Memo[i - 1];
		}
	}

	_getch();
	return 0;
}
