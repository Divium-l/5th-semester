#include "classic.hpp"

Classic::Classic() : Cd() {
    _allocateString(mainTrack, UNDEFINED_STRING);
}

Classic::Classic(const char* mainTrack, const char* performers, 
        const char* label, int selections, double playtime) : Cd(performers, label, selections, playtime) {
    _allocateString(this->mainTrack, mainTrack);
}

Classic::Classic(const Classic& classic) : Cd(classic) {
    _allocateString(mainTrack, classic.mainTrack);
}

Classic::~Classic() {
    _freeAllocatedMemory();
}

void Classic::_freeAllocatedMemory() {
    _freeAllocatedString(mainTrack);
}

Classic& Classic::operator=(const Classic& classic) {
    if (this == &classic)
        return *this;

    _freeAllocatedMemory();
    _allocateString(mainTrack, classic.mainTrack);
    return *this;
}

void Classic::report() {
    std::cout << "{" << "MainTrack: " << mainTrack << "}" << std::endl;
}
