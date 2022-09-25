#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>

using namespace std;
const int DataSize = 144;

std::string IntToHex(int n)
{
	std::stringstream ss;
	ss << std::hex << n;
	return ss.str();
}

/*
4 247 776 274
103 373 407
46 130
29 961
151
56
9
9
*/

// ESP, EBP - БАН
int main()
{
	unsigned char Memo[DataSize];
	for (int i = 0; i++; i < DataSize) {
		Memo[i] = NULL;
	}
	__asm {
		pushad

		MOV ESI, 4247776274
		MOV EBX, 103373407
		// 1-й способ
		XCHG ESI, EBX
		// 2-й способ
		MOV EDI, ESI
		MOV ESI, EBX
		MOV EBX, EDI
		// 3-й способ
		PUSH ESI
		MOV ESI, EBX
		POP EBX


		MOV CX, 46130
		MOV DX, 29961
		// 1
		XCHG CX, DX
		// 2
		MOV DI, CX
		MOV CX, DX
		MOV DX, DI
		// 3
		PUSH CX
		MOV CX, DX
		POP DX


		MOV AL, 151
		MOV AH, 56

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
