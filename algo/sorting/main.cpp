#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <string>
#include <climits>
#include "sort.hpp"

void printArray(const int* array, const size_t size);
void randomizeArray(int* array, const size_t size);
void copyArray(int* to, const int* from, const size_t size);

const unsigned int SIZE = 100'000;
int random_b[SIZE];
int random_q[SIZE];
int sorted_b[SIZE];
int sorted_q[SIZE];

void testSort(int* array, void (*sort)(int*, const unsigned long) ,std::string arrayType, std::string sortType) {
    std::cout << "Sorting " << arrayType << " array using " << sortType << std::endl;
    auto start = std::chrono::system_clock::now();
    sort(array, SIZE);
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Sorting comlete. " << elapsed.count() << "ms elapsed" << std::endl;
}

int main() {
    // Initialization
    for (int i = 0; i < SIZE; i++) {
        sorted_b[i] = i;
        sorted_q[i] = i;
    }
    randomizeArray(random_b, SIZE);
    copyArray(random_q, random_b, SIZE);

    // Quick sort | random array
    testSort(random_q, sort::qsort, "random", "quick sort");

    // Quick sort | sorted array
    testSort(sorted_q, sort::qsort, "sorted", "quick sort");

    // Bubble sort | random array
    testSort(random_b, sort::bsort, "random", "buuble sort");

    // Bubble sort | sorted array
    testSort(sorted_b, sort::bsort, "sorted", "buuble sort");

}

void printArray(const int* array, const size_t size) {
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";

    std::cout << std::endl;
}

void randomizeArray(int* array, const size_t size) {
    std::random_device rd;     
	std::mt19937 rng(rd());    
	std::uniform_int_distribution<int> uni(INT_MIN, INT_MAX);

    for (int i = 0; i < size; i++)
        array[i] = uni(rng);
}

void copyArray(int* to, const int* from, const size_t size) {
    for (int i = 0; i < size; i++) 
        to[i] = from[i];
}