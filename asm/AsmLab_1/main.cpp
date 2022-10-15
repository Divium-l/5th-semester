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
		LEA EAX, c
		MOV BX, [EAX]
		LEA EAX, d
		MOV CX, [EAX]
		LEA EAX, e
		MOV DH, [EAX]
		LEA EAX, f
		MOV DL, [EAX]

		// 1.1
		XCHG ESI, EDI
		// 1.2
		MOV EAX, ESI
		MOV ESI, EDI
		MOV EDI, EAX
		// 1.3
		PUSH ESI
		PUSH EDI
		POP ESI
		POP EDI
		// 1.4
		LEA EAX, data
		MOV [EAX], ESI
		MOV ESI, EDI
		MOV EDI, [EAX]
		// 2.1
		XCHG BX, CX
		// 2.2
		MOV AX, BX
		MOV BX, CX
		MOV CX, AX
		// 2.3
		PUSH BX
		PUSH CX
		POP BX
		POP CX
		// 2.4
		LEA EAX, data
		MOV [EAX], BX
		MOV BX, CX
		MOV CX, [EAX]
		// 3.1
		XCHG DH, DL
		// 3.2
		MOV AL, DH
		MOV DH, DL
		MOV DL, AL
		// 3.3
		PUSH DX
		MOV DH, DL
		POP AX
		MOV DL, AH
		// 3.4
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
	return 0;
}
