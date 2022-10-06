#include "emp.hpp"

using namespace std;

int main(int argc, char** argv) {
    highfink hf = highfink("fn", "ln", "j", "rpo", 12);
    hf.ShowAll();
    hf.SetAll();
    hf.ShowAll();

    return EXIT_SUCCESS;
}