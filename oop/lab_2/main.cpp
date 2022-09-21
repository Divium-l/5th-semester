#include <iostream>
#include "classic.hpp"

using namespace std;

void bravo(Cd& disk);

int main() {
    Cd c1 = Cd("Beatles", "Capitol", 14, 13.5);
    Classic c2 = Classic("Piano Sonata in...", "Alfred Brendel", "Philips", 2, 57.17);

    cout << "Using objects directly" << endl;
    c1.report();
    c2.report();

    cout << "Using pointer to object" << endl;
    Cd *ptrCd = &c1;
    ptrCd->report();
    ptrCd = &c2;
    ptrCd->report();

    cout << "Calling a function by Cd reference argument" << endl;
    bravo(c1);
    bravo(c2);

    cout << "Testing assignemnt" << endl;
    Classic copy;
    copy = c2;
    copy.report();

    return EXIT_SUCCESS;
}

void bravo(Cd& disk) {
    disk.report();
}