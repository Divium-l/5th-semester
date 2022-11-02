#include <ctime>
#include <string>
#include <sstream>

struct TimeRange {
    time_t start;
    time_t end;

    TimeRange() : start(0), end(0) {}
    TimeRange(time_t start, time_t end) : start(start), end(end) {}

    std::string toString() {
        std::stringstream stream;

        stream << "{"
            << "Start: " << start << ", "
            << "End: " << end
            << "}";

        return stream.str();
    }
};