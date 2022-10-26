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
	
	// (c - d + 2)/(b + a - 1) 
	long long a = 0x1'527D'27F2; //5'678'901'234;
	long long b = 0x1'94A8'1B79; //6'789'012'345;
	long long c = 0x1'D649'BAC0; //7'890'123'456;
	long long d = 0x2'128E'0F87; //8'901'234'567; 
	long long e = 0x2'192D'7B4E; //9'012'345'678;
	long long f = 0x2'5B67'B115; //10'123'456'789;
	
	__asm {
		pushad
		// EDX:EAX - ECX:EBX + 2 = EDX:EAX
		// c
		MOV EDX, 0xD649'BAC0
		MOV EAX, 0x1
		// d
		MOV ECX, 0x128E'0F87
		MOV EBX, 0x2
		// c - d
		SUB EDX, ECX
		SBB EAX, EBX
		// c - d + 2
		ADD EDX, 2
		ADC EAX, 0
		LEA ESI, Memo
		MOV [ESI], EDX
		MOV [ESI + 4], EAX

		// ECX:EBX + EDI:ESI - 1 = ECX:EBX
		// b
		MOV ECX, 0x94A8'1B79
		MOV EBX, 0x1
		// a
		MOV EDI, 0x527D'27F2
		MOV ESI, 0x1
		// a + b
		ADD ECX, EDI
		ADC EBX, ESI
		// a + b - 1
		SUB ECX, 1
		SBB EBX, 0
		LEA ESI, Memo
		MOV[ESI + 16], ECX
		MOV[ESI + 20], EBX

		// EDX:EAX / EBX:EDI = EDX:EAX
		/**
		* EDX:EAX = -1'011'111'109 = 0xFFFF'FFFF'C3BB'AB3B
		* EBX:EDI = 12'467'913'578 = 0X0000'0002'E725'436A
		**/

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
