#include <iostream>

#include "wine.hpp"

using namespace std;

int main(int argc, char **argv) {
    string label;
    size_t size = 0;
    cout << "Enter whine name: ";
    cin >> label;
    cout << "Enter number of years: ";
    cin >> size;
    PairArray wineBottles = PairArray(IntArray(size), IntArray(size));
    for (size_t i = 0; i < size; i++) {
        cout << "[" << i + 1 << "]" << " year: ";
        cin >> wineBottles.first[i];
        cout << "[" << i + 1 << "]" << " number of botles: ";
        cin >> wineBottles.second[i];
    }
    Wine wine = Wine(label, wineBottles);

    cout << "Wine = " << wine.toString() << endl;
}