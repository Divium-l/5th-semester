#include <cstring>
#include <iostream>

#include "dynamic_string_allocator.hpp"

class Cd: public DynamicStringAllocator
{
private:
    int selections;
    double playtime;

protected:
    char* performers;
    char* label;
    void _freeAllocatedMemory() override;
    
public:
    Cd(const char* performers, const char* label, int selections, double playtime);
    Cd(const Cd& cd);
    Cd();
    ~Cd();
    Cd& operator=(const Cd& cd);
    virtual void report();
};
