#include "tv_exception.hpp"

TvIsOffException::TvIsOffException() : std::logic_error("") {}

inline const char*  TvIsOffException::what() const noexcept {
    return "Tv is off";
}