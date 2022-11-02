#include <vector>
#include "session.hpp"

class Cinema {
private:
    std::vector<Session> sessions;

public:
    Cinema() : sessions() {}
    Cinema(const std::vector<Session> &sessions) : sessions(sessions) {}

    void addSession(const Session &session) {
        sessions.push_back(session);
    }

    void removeSessionBySessionNumber(const int sessionNumber) {
        auto iterator = sessions.begin();

        for (Session session : sessions) {
            if (session.getSessionNumber() == sessionNumber)
                break;
            iterator++;
        }

        sessions.erase(iterator);
    }

    std::vector<Session> getActiveSessions() {
        std::vector<Session> activeSessions();

        for (Session session : sessions) {
            auto time = session.getSessionTime();
        }
    }
};