#pragma once

#include <vector>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "session.hpp"

class Cinema {
private:
    std::vector<Session> sessions;

public:
    Cinema();
    Cinema(const std::vector<Session> &sessions);

    void addSession(const Session &session);

    std::vector<Session> sortBySessionNumber();
    std::vector<Session> sortByHallNumber();
    std::vector<Session> sortByMovieName();
    std::vector<Session> sortByTicketPrice();
    std::vector<Session> sortByStartTime();
    std::vector<Session> sortByEndTime();

    std::vector<Session> findBySessionNumber(const int sessionNumber);
    std::vector<Session> findByHallNumber(const int hallNumber);
    std::vector<Session> findByMovieName(const std::string &movieName);
    std::vector<Session> findByTicketPrice(const double ticketPrice);
    std::vector<Session> findByStartTime(const time_t start);
    std::vector<Session> findByEndTime(const time_t end);

    void removeSessionBySessionNumber(const int sessionNumber);

    std::vector<Session> getActiveSessions() const;
    std::vector<Session> getAllSessions() const;
    std::vector<Session> &getAllSessionsRef();

    void serialize(std::string path) const;
    void deserialize(std::string path);
};
