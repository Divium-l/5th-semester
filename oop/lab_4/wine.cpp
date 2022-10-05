#include "wine.hpp"

void Wine::_copyIntoIntArray(IntArray &destination, const int *source) {
    for (size_t i = 0; i < destination.size(); i++)
        destination[i] = source[i];
}

Wine::Wine() {
    label = "unsigned";
    _size = 0;
    bottles.first = IntArray(_size);
    bottles.second = IntArray(_size);
}

Wine::Wine(const std::string label, const int size, const int years[], const int ammount[]) {
    this->label = label;
    this->bottles.first = IntArray(size);
    _copyIntoIntArray(this->bottles.first, years);
    this->bottles.second = IntArray(size);
    _copyIntoIntArray(this->bottles.second, ammount);
}

Wine::Wine(const std::string label, const IntArray &years, const IntArray &ammount) {
    if (years.size() != ammount.size())
        throw std::invalid_argument("Arrays' length do not match");

    this->label = label;
    this->bottles.first = years;
    this->bottles.second = ammount;
    this->_size = years.size();
}

Wine::Wine(const std::string label, const PairArray &pair) : Wine(label, pair.first, pair.second) {}

std::string Wine::getLabel() const {
   return label;
}

int Wine::getSum()const {
    int count = 0;
    for (int ammount : bottles.second)
        count += ammount;
    return count;
}

PairArray Wine::getBottles() const {
    return this->bottles;
}

void Wine::setLabel(const std::string label) {
    this->label = label;
}

void Wine::setBottles(const int size, const int years[], const int bottles[]) {
    this->_size = size;
    this->bottles.first.resize(size);
    this->bottles.second.resize(size);
    _copyIntoIntArray(this->bottles.first, years);
    _copyIntoIntArray(this->bottles.first, bottles);
}

void Wine::setBottles(const IntArray &years, const IntArray &bottles) {
    if (years.size() != bottles.size())
        throw std::invalid_argument("Arrays' length do not match");
    this->_size = years.size();
    this->bottles.first = years;
    this->bottles.second = bottles;
}

std::string Wine::toString() const {
    auto stream = std::stringstream();
    stream << "{" << "Label: " << label << ", "
        << "Bottles [year: ammount]: {";
    for (size_t i = 0; i < _size; i++) {
        stream << "[" << bottles.first[i] << ": " << bottles.second[i] << "]";
        if (i != _size - 1)
            stream << ", ";
    }
    stream << "}}";
    return stream.str();
}