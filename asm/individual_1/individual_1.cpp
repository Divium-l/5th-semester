#include <iostream>
#include <random>

const int32_t MIN = 0;
const int32_t MAX = 16;
const uint32_t ARR_SIZE = 3;

void randomizeSquareMatrix(int** arr, const int size);
void randomizeArray(int* arr, const int size);

int main()
{
    // index = 0..2
    // result = X * ΣA_i + X^2 * ΣB_ij
    // 2147483647
    int a[ARR_SIZE] = {1, 2, 3 };
    int b[ARR_SIZE][ARR_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int x = 10;
    int result = 0;

    int res_sum_a = 0;
    int res_sum_b = 0;
    int res_mult_1 = 0;
    int res_mult_2 = 0;
    int overflow = 0;

    __asm {
        pushad

        JMP _start

        // func_arr_sum(uint* arrPtr, uint size) -> int sum
        // func_arr_sum(uint* EAX   , uint ECX ) -> int EBX
    func_arr_sum:
        XOR EBX, EBX

    loop_func_sum:
        ADD EBX, [EAX]
        ADD EAX, 4
        LOOP loop_func_sum

        ret

    _start:
        // ΣA_i
        LEA EAX, a
        MOV ECX, 3
        CALL func_arr_sum
        ///debug//////////////////
        LEA EAX, res_sum_a      //
        MOV [EAX], EBX          //
        ///debug//////////////////
        
        // X * ΣA_i
        LEA EAX, x
        MOV EAX, [EAX]
        IMUL EBX
        ///debug//////////////////
        LEA ECX, res_mult_1     //
        MOV[ECX], EAX           //
        ///debug//////////////////
        PUSH EAX

        // ΣB_ij
        LEA EAX, b
        MOV ECX, 9
        CALL func_arr_sum
        ///debug//////////////////
        LEA EAX, res_sum_b      //
        MOV [EAX], EBX          //
        ///debug//////////////////
        
        // X^2 * ΣB_ij
        LEA EAX, x
        MOV EAX, [EAX]
        IMUL EAX
        IMUL EBX
        ///debug//////////////////
        LEA ECX, res_mult_2     //
        MOV [ECX], EAX          //
        ///debug//////////////////

        // X * ΣA_i + X^2 * ΣB_ij
        POP EBX
        ADD EAX, EBX

        // output
        LEA ECX, result
        MOV [result], EAX

        JMP _end

    _end_overflow:
        LEA EAX, overflow
        MOV [EAX], 1
    _end:
        popad
    }

    if (overflow)
        std::cout << "Overflow! Unable to proccess." << std::endl;
    else
        std::cout << "Result = " << result << std::endl;

    std::cout << std::endl << "Debug info:" << std::endl;
    std::cout << "res_sum_a = " << res_sum_a << std::endl;
    std::cout << "res_mult_1 = " << res_mult_1 << std::endl;
    std::cout << "res_sum_b = " << res_sum_b << std::endl;
    std::cout << "res_mult_2 = " << res_mult_2 << std::endl;
    std::cout << "result = " << result << std::endl;
    std::cout << "overflow = " << (overflow ? "true" : "false") << std::endl;
}

void randomizeSquareMatrix(int** arr, const int size) {
    for (int i = 0; i < size; i++)
        randomizeArray(arr[i], size);
}

void randomizeArray(int* arr, const int size) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int32_t> uni(MIN, MAX);

    for (int i = 0; i < size; i++)
        arr[i] = uni(rng);
}