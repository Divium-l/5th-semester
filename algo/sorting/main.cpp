#include <iostream>
#include <random>
#include "sort.hpp"

void printArray(const int* array, const size_t size);
void randomizeArray(int* array, const size_t size);
void copyArray(int* to, const int* from, const size_t size);

int main() {
    int random_b[1000];
    int random_q[1000];

    int sorted_q[1000];
    int sorted_q[1000];

    int a[] = {2, 3, 0, -1};
    int b[] = {2, 3, 0, -1};

    sort::bsort(a, 4);
    printArray(a, 4);

    sort::qsort(b, 4);
    printArray(b, 4);

}

void printArray(const int* array, const size_t size) {
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;
}

void randomizeArray(int* array, const size_t size) {
    std::random_device rd;     
	std::mt19937 rng(rd());    
	std::uniform_int_distribution<int> uni(0, 100);

    for (int i = 0; i < size; i++)
        array[i] = uni(rng);
}

void copyArray(int* to, const int* from, const size_t size) {
    for (int i = 0; i < size; i++) 
        to[i] = from[i];
}