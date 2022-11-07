#include "cinema.hpp"

Cinema::Cinema() : sessions() {}
Cinema::Cinema(const std::vector<Session> &sessions) : sessions(sessions) {}

void Cinema::addSession(const Session &session) {
    sessions.push_back(session);
}

void Cinema::removeSessionBySessionNumber(const int sessionNumber) {
    auto iterator = sessions.begin();

    for (Session session : sessions) {
        if (session.getSessionNumber() == sessionNumber)
            break;
        iterator++;
    }

    sessions.erase(iterator);
}

std::vector<Session> Cinema::getActiveSessions() const {
    auto activeSessions = std::vector<Session>();

    for (Session session : sessions) {
        auto time = session.getTimeRange();
        if (time.inRange(std::time(0)))
            activeSessions.push_back(session);
    }

    return activeSessions;
}

std::vector<Session> Cinema::getAllSessions() const {
    return sessions;
}