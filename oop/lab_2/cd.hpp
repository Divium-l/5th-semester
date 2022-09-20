#include <cstring>
#include <iostream>

class Cd
{
private:
    char* performers;
    char* label;
    int selections;
    double playtime;

    void _allocateString(char* ptr, const char* str);
    void _freeAllocatedString(char* ptr);
    void _freeAllocatedMemory();
public:
    Cd(const char* performers, const char* label, int selections, double playtime);
    Cd(const Cd& cd);
    Cd();
    
    ~Cd();
    void report();
    Cd& operator=(const Cd& cd);
};

