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

void Cinema::serialize(std::string path) const {
    auto out = std::ofstream();
    out.open(path);
    for (auto session: sessions) {
        out << session.getSessionNumber() << " "
            << session.getHallNumber() << " "
            << session.getTicketPrice() << " "
            << session.getTimeRange().start << " "
            << session.getTimeRange().end << " "
            << session.getMovieName() << "\n";
    }
    out.close();
}

void Cinema::deserialize(std::string path) {
    auto in = std::ifstream();
    in.open(path);
    auto line = std::string();
    sessions.clear();  
    while(!in.fail()) {
        int sessionNumber, hallNumber;
        std::string movieName;
        double ticketPrice;
        long long start, end;
        in >> sessionNumber >> hallNumber >> ticketPrice >> start >> end >> movieName;
        sessions.push_back(
            Session(sessionNumber, hallNumber, movieName, ticketPrice, TimeRange(start, end))
        );
        sessions.erase(sessions.end() - 1);
    }
    in.close();
}