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

	// ((25/c) - d + 2)/(b + a^2 - 1) 
	// (c - d + 2)/(b + a - 1) 
	long long a = 0x1'527D'27F2; //5'678'901'234;
	long long b = 0x1'94A8'1B79; //6'789'012'345;
	long long c = 0x1'D649'BAC0; //7'890'123'456;
	long long d = 0x2'128E'0F87; //8'901'234'567; 
	long long e = 0x2'192D'7B4E; //9'012'345'678;
	long long f = 0x2'5B67'B115; //10'123'456'789;
	long long result = 0;
	
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
		SUB EDX, 2
		SBB EAX, 0

		// EBX:EDI + EDX:ESI - 1 = EBX:EDI
		// b
		MOV EBX, 0x94A8'1B79
		MOV EDI, 0x1
		// a
		MOV EDX, 0x527D'27F2
		MOV ESI, 0x1
		// a + b
		ADD EBX, EDX
		ADC EDI, ESI
		// a + b - 1
		SUB EBX, 1
		SBB EDI, 0

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
