#pragma once

#include <vector>
#include <ctime>
#include "session.hpp"

class Cinema
{
private:
    std::vector<Session> sessions;

public:
    Cinema();
    Cinema(const std::vector<Session> &sessions);

    void addSession(const Session &session);

    void removeSessionBySessionNumber(const int sessionNumber);

    std::vector<Session> getActiveSessions() const;
    std::vector<Session> getAllSessions() const;
};
