#include "time_range.hpp"

TimeRange::TimeRange() : start(0), end(0) {}
TimeRange::TimeRange(time_t start, time_t end) : start(start), end(end) {}

std::string TimeRange::toString() const {
    std::stringstream stream;

    stream << "{"
           << "Start: " << start << ", "
           << "End: " << end
           << "}";

    return stream.str();
}

bool TimeRange::inRange(const time_t time) const {
    return time >= start && time <= end;// || (time < end && time > );
}

/*
bool TimeRange::inRangeOf(const time_t time, const time_t offset) const {
    return time >= start - offset && time <= end;
}*/