#pragma once

#include <valarray>
#include <string>
#include <sstream>

typedef std::valarray<int> IntArray;
typedef std::pair<IntArray, IntArray> PairArray;

class Wine {
private:
    std::string label;
    PairArray bottles;
    size_t _size;
protected:
    void _copyIntoIntArray(IntArray &destination, const int *source);
public:
    Wine();
    Wine(const std::string label, const int size, const int years[], const int ammount[]);
    Wine(const std::string label, const IntArray &years, const IntArray &ammount);
    Wine(const std::string label, const PairArray &pair);
    std::string getLabel() const;
    PairArray getBottles() const;
    int getSum() const;
    void setLabel(const std::string label);
    void setBottles(const int size, const int years[], const int ammount[]);
    void setBottles(const IntArray &years, const IntArray &ammount);
    std::string toString() const;
};