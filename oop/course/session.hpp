#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include "time_range.hpp"

class Session {
private:
    int sessionNumber;
    int hallNumber;
    std::string movieName;
    double ticketPrice;
    TimeRange sessionTime;

public:
    Session(const int sessionNumber, const int hallNumber, const std::string &movieName,
        const double ticketPrice, const TimeRange &sessionTime);

    std::string toString() const;

    int getSessionNumber() const;
    int getHallNumber() const;
    std::string getMovieName() const;
    double getTicketPrice() const;
    TimeRange getTimeRange() const;

    void setSessionNumber(const int sessionNumber);
    void setHallNumber(const int hallNumber);
    void setMovieName(const std::string &moviName);
    void setTicketPrice(const double ticketPrice);
    void setTimeRange(const TimeRange &sessionTime);
    void setTimeStart(const time_t end);
    void setTimeEnd(const time_t start);
};