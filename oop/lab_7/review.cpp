#include "review.hpp"

Review::Review(const std::wstring &text, const int8_t rating) {
    this->text = text;
    this->rating = rating;
}

Review::~Review() {
    std::wcout << "Destroying review " << "\'" << text << "\'" << std::endl;
}

std::wstring Review::getText() const { return text; }
int8_t Review::getRating() const { return rating; };

std::wstring Review::toString() const {
    auto stream = std::wstringstream();

    stream << "{"
        << "Title: " << text << ", "
        << "Rating: " << rating
        << "}";

    return stream.str();
}

void Review::print() const {
    std::wcout << toString() << std::endl;
}