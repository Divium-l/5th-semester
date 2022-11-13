#include <iostream>
#include <random>

const int32_t MIN = -255;
const int32_t MAX = 255;
const uint32_t ARR_SIZE = 3;

int random();
void randomizeArray(int arr[ARR_SIZE], const int size);
void randomizeSquareMatrix(int arr[ARR_SIZE][ARR_SIZE], const int size);

int main()
{
    int32_t a[ARR_SIZE] = { 1, 2, 3 };
    int32_t b[ARR_SIZE][ARR_SIZE] = { {1, 2, 3}, {4, -5, 6}, {7, 8, 9} };
    int32_t x = -10;
    int32_t result = 0;
    /*
    randomizeArray(a, ARR_SIZE);
    randomizeSquareMatrix(b, ARR_SIZE);
    x = random();
    */
    int32_t res_sum_a = 0;
    int32_t res_sum_b = 0;
    int32_t res_mult_1 = 0;
    int32_t res_mult_2 = 0;
    bool overflow = 0;

    // result = X * ΣA_i + X^2 * ΣB_ij
    __asm {
        pushad
        JMP _start

    // func_arr_sum(uint* arrPtr, uint size) -> int sum
    // func_arr_sum(uint* EAX   , uint ECX ) -> int EBX
    _func_arr_sum:
        XOR EBX, EBX

    loop_func_sum:
        ADD EBX, [EAX]
        JO _func_end
        ADD EAX, 4
        LOOP loop_func_sum
    _func_end:
        ret
    // func end

    _start:
        // ΣA_i
        LEA EAX, a
        MOV ECX, 3
        CALL _func_arr_sum
        JO _end_overflow
        ///debug//////////////////
        LEA EAX, res_sum_a      //
        MOV [EAX], EBX          //
        ///debug//////////////////
        
        // X * ΣA_i
        LEA EAX, x
        MOV EAX, [EAX]
        IMUL EBX
        JO _end_overflow
        ///debug//////////////////
        LEA ECX, res_mult_1     //
        MOV[ECX], EAX           //
        ///debug//////////////////
        MOV ESI, EAX

        // ΣB_ij
        LEA EAX, b
        MOV ECX, 9
        CALL _func_arr_sum
        JO _end_overflow
        ///debug//////////////////
        LEA ECX, res_sum_b      //
        MOV [ECX], EBX          //
        ///debug//////////////////

        // X^2 * ΣB_ij
        LEA EAX, x
        MOV EAX, [EAX]
        IMUL EAX
        JO _end_overflow
        IMUL EBX
        JO _end_overflow
        ///debug//////////////////
        LEA ECX, res_mult_2     //
        MOV [ECX], EAX          //
        ///debug//////////////////

        // X * ΣA_i + X^2 * ΣB_ij
        ADD EAX, ESI
        JO _end_overflow

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

int random() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int32_t> uni(MIN, MAX);

    return uni(rng);
}

void randomizeArray(int arr[ARR_SIZE], const int size) {
    for (int i = 0; i < size; i++)
        arr[i] = random();
}

void randomizeSquareMatrix(int arr[ARR_SIZE][ARR_SIZE], const int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            arr[i][j] = random();
}
