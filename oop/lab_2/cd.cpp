#include "cd.hpp"

void Cd::_freeAllocatedMemory() {
    _freeAllocatedString(performers);
    _freeAllocatedString(label);
}

Cd::Cd() {
    _allocateString(performers, UNDEFINED_STRING);
    _allocateString(label, UNDEFINED_STRING);
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const char* performers, const char* label, int selections, double playtime) {
    _allocateString(this->performers, performers);
    _allocateString(this->label, label);
    this->selections = selections;
    this->playtime = playtime;
}

Cd::Cd(const Cd& cd) {
    _allocateString(performers, cd.performers);
    _allocateString(label, cd.label);
    selections = cd.selections;
    playtime = cd.playtime;
}

Cd& Cd::operator=(const Cd& cd) {
    if (this == &cd)
        return *this;

    _freeAllocatedMemory();

    _allocateString(performers, cd.performers);
    _allocateString(label, cd.label);
    selections = cd.selections;
    playtime = cd.playtime;
    return *this;
}

Cd::~Cd() {
    _freeAllocatedMemory();
}

void Cd::report() {
    std::cout << "{" << "Performers: " << performers << ", "
        << "Label: " << label << ", "
        << "Selections: " << selections << ", "
        << "Playtime: " << playtime << "}" << std::endl;
}
