#include "cd.hpp"

void Cd::_allocateString(char* ptr, const char* str) {
    size_t length = strlen(str);
    ptr = new char[length];
    strcpy(ptr, str);
}

void Cd::_freeAllocatedString(char* ptr) {
    if (ptr != nullptr) {
        delete[] ptr;
        ptr = nullptr;
    }
}

void Cd::_freeAllocatedMemory() {
    _freeAllocatedString(performers);
    _freeAllocatedString(label);
}

Cd::Cd()
{
    _allocateString(performers, "undefined");
    _allocateString(label, "undefined");
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const char* performers, const char* label, int selections, double playtime)
{
    _allocateString(this->performers, performers);
    _allocateString(this->label, label);
    this->selections = selections;
    this->playtime = playtime;
}

Cd::Cd(const Cd& cd) 
{
    _allocateString(performers, cd.performers);
    _allocateString(label, cd.label);
    selections = cd.selections;
    playtime = cd.playtime;
}

Cd& Cd::operator=(const Cd& cd) 
{
    _freeAllocatedMemory();

    _allocateString(performers, cd.performers);
    _allocateString(label, cd.label);
    selections = cd.selections;
    playtime = cd.playtime;
}

Cd::~Cd()
{
    _freeAllocatedMemory();
}

void Cd::report() {
    std::cout << "{" << "Performers: " << performers << ", "
        << "Label: " << label << ", "
        << "Selections" << selections << ", "
        << "Playtime" << playtime << "}";
}