// add char array containing main track on a CD
#include "cd.hpp"

class Classic: public Cd {
protected:
    char* mainTrack;
    void _freeAllocatedMemory() override;

public:
    Classic();
    Classic(const char* mainTrack, const char* performers, 
        const char* label, int selections, double playtime);
    Classic(const Classic& classic);
    ~Classic();
    Classic& operator=(const Classic& classic);
    void report() override;
};
