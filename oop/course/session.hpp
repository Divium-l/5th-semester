#include <string>
#include <sstream>
#include <iomanip>

struct SessionTime {
    time_t start;
    time_t end;

    SessionTime() : start(0), end(0) {}
    SessionTime(time_t start, time_t end) : start(start), end(end) {}

    std::string toString() {
        std::stringstream stream;

        stream << "{"
            << "Start: " << start << ", "
            << "End: " << end
            << "}";

        return stream.str();
    }
};

class Session {
private:
    int sessionNumber;
    int hallNumber;
    std::string movieName;
    double ticketPrice;
    SessionTime sessionTime;

public:
    Session(const int sessionNumber, const int hallNumber, const std::string &movieName,
        const double ticketPrice, const SessionTime &sessionTime) {
        this->sessionNumber = sessionNumber;
        this->hallNumber = hallNumber;
        this->movieName = movieName;
        this->ticketPrice = ticketPrice;
        this->sessionTime = sessionTime;
    }

    std::string toString() const {
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

    int getSessionNumber() const {
        return sessionNumber;
    }

    SessionTime getSessionTime() const {
        return sessionTime;
    }
};