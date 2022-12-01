#pragma once

#include <ctime>
#include <string>
#include <sstream>

struct TimeRange {
    typedef unsigned long long u64;
    static const u64 SECOND = 1000;
    static const u64 MINUTE = SECOND * 60;
    static const u64 HOUR = MINUTE * 60;
    static const u64 DAY = HOUR * 24;
    static const u64 WEEK = DAY * 7;

    time_t start;
    time_t end;

    TimeRange();
    TimeRange(time_t start, time_t end);

    std::string toString() const;
    bool inRange(const time_t time) const;
};