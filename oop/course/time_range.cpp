#include "time_range.hpp"

TimeRange::TimeRange() : start(0), end(0) {}
TimeRange::TimeRange(time_t start, time_t end) : start(start), end(end) {}

std::string TimeRange::toString() const {
    std::stringstream stream;
    char startTimeBuffer[32], endTimeBuffer[32];

    std::tm *ptm = std::localtime(&start);
    std::strftime(startTimeBuffer, 32, "%d.%m.%Y %H:%M:%S", ptm);

    ptm = std::localtime(&end);
    std::strftime(endTimeBuffer, 32, "%d.%m.%Y %H:%M:%S", ptm);

    stream << "{"
           << "Start: " << startTimeBuffer << ", "
           << "End: " << endTimeBuffer
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