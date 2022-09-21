#include <cstring>
#define UNDEFINED_STRING "undefined"

class DynamicStringAllocator {
protected:
    char* _allocateString(const char* source);
    void _allocateString(char*& destination, const char* source);
    void _freeAllocatedString(char* ptr);
    virtual void _freeAllocatedMemory() = 0;
};
