#include "dynamic_string_allocator.hpp"

char* DynamicStringAllocator::_allocateString(const char* source) {  
    char* destination = nullptr;
    destination = new char[strlen(source)];
    strcpy(destination, source);
    return destination;
}

void DynamicStringAllocator::_allocateString(char* destination, const char* source) {
    destination = new char[strlen(source)];
    strcpy(destination, source);
}


void DynamicStringAllocator::_freeAllocatedString(char* ptr) {
    if (ptr == nullptr)
        return;

    delete[] ptr;
    ptr = nullptr;
}