#include "session.hpp"

Session::Session(const int sessionNumber, const int hallNumber, const std::string &movieName,
        const double ticketPrice, const TimeRange &sessionTime) {
    this->sessionNumber = sessionNumber;
    this->hallNumber = hallNumber;
    this->movieName = movieName;
    this->ticketPrice = ticketPrice;
    this->sessionTime = sessionTime;
}

std::string Session::toString() const {
    std::stringstream stream;

    stream << "{"
           << "Session Number: " << sessionNumber << ", "
           << "Hall Number: " << hallNumber << ", "
           << "Movie Name: " << movieName << ", "
           << "Ticket Price: " << std::fixed << std::setprecision(2) << ticketPrice << ", "
           << "Session Number: " << sessionNumber << ", "
           << "Time: " << sessionTime.toString()
           << "}";

    return stream.str();
}

void Session::setSessionNumber(const int sessionNumber) { this->sessionNumber = sessionNumber; }
void Session::setHallNumber(const int hallNumber) { this->hallNumber = hallNumber; }
void Session::setMovieName(const std::string &movieName) { this->movieName = movieName; }
void Session::setTicketPrice(const double ticketPrice) { this->ticketPrice = ticketPrice; }
void Session::setTimeRange(const TimeRange &sessionTime) { this->sessionTime = sessionTime; }

int Session::getSessionNumber() const { return sessionNumber; }
int Session::getHallNumber() const { return hallNumber; }
std::string Session::getMovieName() const { return movieName; }
double Session::getTicketPrice() const { return ticketPrice; }
TimeRange Session::getTimeRange() const { return sessionTime; }