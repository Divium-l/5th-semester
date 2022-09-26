#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>

using namespace std;

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
	unsigned int data = 0;
	char32_t a = 4247776274;	// ESI
	char32_t b = 103373407;		// EDI
	char16_t c = 46130;			// BX	(EBX)
	char16_t d = 29961;			// CX	(ECX)
	char e = 151;				// DH	(EDX)
	char f = 56;				// DL	(EDX)
	__asm {
		pushad

		LEA EAX, a
		MOV ESI, [EAX]
		LEA EAX, b
		MOV EDI, [EAX]
		// 1-й способ
		XCHG ESI, EDI
		// 2-й способ
		MOV EAX, ESI
		MOV ESI, EDI
		MOV EDI, EAX
		// 3-й способ
		PUSH ESI
		PUSH EDI
		POP ESI
		POP EDI
		// 4-й способ
		LEA EAX, data
		MOV [EAX], ESI
		MOV ESI, EDI
		MOV EDI, [EAX]


		LEA EAX, c
		MOV BX, [EAX]
		LEA EAX, d
		MOV CX, [EAX]
		// 1
		XCHG BX, CX
		// 2
		MOV AX, BX
		MOV BX, CX
		MOV CX, AX
		// 3
		PUSH BX
		PUSH CX
		POP BX
		POP CX
		// 4
		LEA EAX, data
		MOV [EAX], BX
		MOV BX, CX
		MOV CX, [EAX]


		LEA EAX, e
		MOV DH, [EAX]
		LEA EAX, f
		MOV DL, [EAX]
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


		// Без потери знака
		MOVSX AX, DH
		MOVSX BX, DL
		// Расширенные нулём
		MOVZX ECX, DH
		MOVZX EDX, DL

		popad
	}

	_getch();
	return 0;
}
