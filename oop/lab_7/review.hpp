#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Review {
    std::wstring text;
    int8_t rating;

public:
    Review(const std::wstring &text = L"", const int8_t rating = 0);
    ~Review();

    std::wstring getText() const;
    int8_t getRating() const;
    
    std::wstring toString() const;

    void print() const;
};
