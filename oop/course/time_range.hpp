#pragma once

#include <ctime>
#include <string>
#include <sstream>

struct TimeRange {
    time_t start;
    time_t end;

    TimeRange();
    TimeRange(time_t start, time_t end);

    std::string toString() const;
    bool inRange(const time_t time) const;
};