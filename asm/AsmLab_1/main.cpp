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
	int data;
	__asm {
		pushad

		MOV ESI, 4247776274
		MOV EDI, 103373407
		// 1-й способ
		XCHG ESI, EDI
		// 2-й способ
		MOV EAX, ESI
		MOV ESI, EDI
		MOV EDI, EAX
		// 3-й способ
		PUSH ESI
		MOV ESI, EDI
		POP EDI
		// 4-й способ
		LEA EAX, data
		MOV [EAX], ESI
		MOV ESI, EDI
		MOV EDI, [EAX]


		MOV EBX, 0
		MOV BX, 46130
		MOV CX, 29961
		// 1
		XCHG BX, CX
		// 2
		MOV AX, BX
		MOV BX, CX
		MOV CX, AX
		// 3
		PUSH BX
		MOV BX, CX
		POP CX
		// 4
		LEA EAX, data
		MOV [EAX], BX
		MOV BX, CX
		MOV CX, [EAX]


		MOV DH, 151
		MOV DL, 56
		// 1
		XCHG DH, DL
		// 2
		MOV AL, DH
		MOV DH, DL
		MOV DL, AL
		// 3
		PUSH DX
		MOV DH, DL
		POP AX
		MOV DL, AH
		// 4
		LEA EAX, data
		MOV [EAX], DH
		MOV DH, DL
		MOV DL, [EAX]

		// ????
		MOVSX AX, DH
		MOVSX EBX, DH

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
