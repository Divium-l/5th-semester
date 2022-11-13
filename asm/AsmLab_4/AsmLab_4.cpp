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
	
	uint32_t number = 0x47AC'2EFA;
	//uint32_t number = 0b1111'0000'1111'0000'1111'0000'1111'0001;
	
	uint32_t zeroes_1 = 0;
	uint32_t ones_1 = 0;
	uint32_t zeroes_2 = 0;
	uint32_t ones_2 = 0;
	uint32_t pairsOfZeroes = 0;
	uint32_t pairsOfOnes = 0;
	uint32_t numberWithSwappedBits = 0;

	__asm {
		pushad
		JMP _start

	// func_swap_bits(uint16 bitIndex_1, uint16 bitIndex_2) -> uint16 swappedRegister AX
	// func_swap_bits(uint16 CX        , uint16 DX        ) -> uint16 AX
	_func_swap_bits:
		MOV BX, AX
		BT BX, CX
		JC set_bit_1
	reset_bit_1:
		BTR AX, DX
		JMP swap_second_bit
	set_bit_1:
		BTS AX, DX

	swap_second_bit:
		BT BX, DX
		JC set_bit_2
	reset_bit_2:
		BTR AX, CX
		JMP _func_exit
	set_bit_2:
		BTS AX, CX

	_func_exit:
		ret
	// func_end


	_start:
		LEA EBX, number
		MOV EAX, [EBX]

	// 1.1 Method 1 - count ones and zeroes

		// EDI - zeroes counter
		// ESI - ones counter
		XOR EDI, EDI
		XOR ESI, ESI

		MOV ECX, 32
	loop_count_1:
		ROR EAX, 1
		JC increment_ones_counter_1

	increment_zeroes_counter_1 :
		INC EDI
		JMP continue_loop_1

	increment_ones_counter_1 :
		INC ESI
		JMP continue_loop_1

	continue_loop_1:
		LOOP loop_count_1

		LEA EBX, zeroes_1
		MOV [EBX], EDI
		LEA EBX, ones_1
		MOV [EBX], ESI


	// 1.2 Method 2 - count ones and zeroes

		// EDI - zeroes counter
		// ESI - ones counter
		XOR EDI, EDI
		XOR ESI, ESI

		MOV ECX, 32
	loop_count_2:
		BT EAX, ECX
		JC increment_ones_counter_2

	increment_zeroes_counter_2:
		INC EDI
		JMP continue_loop_2

	increment_ones_counter_2:
		INC ESI
		JMP continue_loop_2

	continue_loop_2:
		LOOP loop_count_2
	
		LEA EBX, zeroes_2
		MOV [EBX], EDI
		LEA EBX, ones_2
		MOV [EBX], ESI


	// 2 - count pairs
		// EDI - pairs of zeroes counter
		// ESI - pairs of ones counter
		XOR EDI, EDI
		XOR ESI, ESI
		MOV ECX, 1
		PUSH EAX

	loop_pairs_start:
		CMP ECX, 32
		JGE loop_pairs_exit
		XOR EBX, EBX

		SHLD EBX, EAX, 2
		CMP EBX, 0x0000'0003
		JZ pair_of_ones
		CMP EBX, 0x0000'0000
		JZ pair_of_zeroes

		ADD ECX, 1
		SHL EAX, 1
		JMP loop_pairs_start
	pair_of_zeroes:
		INC EDI
		JMP adjust_bitshift
	pair_of_ones:
		INC ESI
	adjust_bitshift:
		ADD ECX, 2
		SHL EAX, 2
		JMP loop_pairs_start
	loop_pairs_exit:

		LEA EBX, pairsOfZeroes
		MOV [EBX], EDI
		LEA EBX, pairsOfOnes
		MOV [EBX], ESI
		POP EAX


	// 3 - swap bits in lower byte (AL)
		// for (i = 7; i >= 0; i--);
		MOV ECX, 3
	loop_swap_bits:
		MOV DX, 7
		SUB DX, CX
		CALL _func_swap_bits
		LOOP loop_swap_bits
	MOV DX, 7
	CALL _func_swap_bits

		LEA EBX, numberWithSwappedBits
		MOV [EBX], EAX

		popad
	}

	std::cout << "number: 0b" << std::bitset<32>(number) << " | "  << "0x" << intToHex(number) << " | " << number << std::endl;
	std::cout << std::setw(23) << "1.1 number of zeroes: " << zeroes_1 << std::endl;
	std::cout << std::setw(23) << "1.1 number of ones: " << ones_1 << std::endl;
	std::cout << std::setw(23) << "1.2 number of zeroes: " << zeroes_2 << std::endl;
	std::cout << std::setw(23) << "1.2 number of ones: " << ones_2 << std::endl;
	std::cout << std::setw(23) << "2 number of pairs of zeroes: " << pairsOfZeroes << std::endl;
	std::cout << std::setw(23) << "2 number of pairs of ones: " << pairsOfOnes << std::endl;
	std::cout << "original number and number with swapped bits 0-7, 1-6, 2-5, 3-4" << std::endl;
	std::cout << "0b" << std::bitset<32>(number) << " | " << "0x" << intToHex(number) << " | " << number << std::endl;
	std::cout << "0b" << std::bitset<32>(numberWithSwappedBits) << " | " << "0x" << intToHex(numberWithSwappedBits) << " | " << numberWithSwappedBits << std::endl;
	std::cout << std::endl;

	_getch();
	return 0;
}
