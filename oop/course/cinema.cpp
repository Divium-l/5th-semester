#include "cinema.hpp"

Cinema::Cinema() : sessions() {}
Cinema::Cinema(const std::vector<Session> &sessions) : sessions(sessions) {}

void Cinema::addSession(const Session &session) {
    sessions.push_back(session);
}

#pragma region sorting
std::vector<Session> Cinema::sortBySessionNumber() {
    auto vector = sessions;
    std::sort(vector.begin(), 
        vector.end(), 
        [](Session session_1, Session session_2) {
            return session_1.getSessionNumber() < session_2.getSessionNumber();
    });
    return vector;
}

std::vector<Session> Cinema::sortByHallNumber() {
    auto vector = sessions;
    std::sort(vector.begin(), 
        vector.end(), 
        [](Session session_1, Session session_2) {
            return session_1.getHallNumber() < session_2.getHallNumber();
    });
    return vector;
}

std::vector<Session> Cinema::sortByMovieName() {
    auto vector = sessions;
    std::sort(vector.begin(), 
        vector.end(), 
        [](Session session_1, Session session_2) {
            return session_1.getMovieName().compare(session_2.getMovieName()) < 0;
    });
    return vector;
}

std::vector<Session> Cinema::sortByTicketPrice() {
    auto vector = sessions;
    std::sort(vector.begin(), 
        vector.end(), 
        [](Session session_1, Session session_2) {
            return session_1.getTicketPrice() < session_2.getTicketPrice();
    });
    return vector;
}

std::vector<Session> Cinema::sortByStartTime() {
    auto vector = sessions;
    std::sort(vector.begin(), 
        vector.end(), 
        [](Session session_1, Session session_2) {
            return session_1.getTimeRange().start < session_2.getTimeRange().start;
    });
    return vector;
}

std::vector<Session> Cinema::sortByEndTime() {
    auto vector = sessions;
    std::sort(vector.begin(), 
        vector.end(), 
        [](Session session_1, Session session_2) {
            return session_1.getTimeRange().end < session_2.getTimeRange().end;
    });
    return vector;
}
#pragma endregion sorting

#pragma region finding
std::vector<Session> Cinema::findBySessionNumber(const int sessionNumber) {
    std::vector<Session> vector;
    std::copy_if(sessions.begin(), 
        sessions.end(), 
        std::back_inserter(vector), 
        [sessionNumber](Session session) {
            return session.getSessionNumber() == sessionNumber;
    });
    return vector;
}

std::vector<Session> Cinema::findByHallNumber(const int hallNumber) {
    std::vector<Session> vector;
    std::copy_if(sessions.begin(), 
        sessions.end(), 
        std::back_inserter(vector), 
        [hallNumber](Session session) {
            return session.getHallNumber() == hallNumber;
    });    
    return vector;
}

std::vector<Session> Cinema::findByMovieName(const std::string &movieName) {
    std::vector<Session> vector;
    std::copy_if(sessions.begin(), 
        sessions.end(), 
        std::back_inserter(vector), 
        [movieName](Session session) {
            return session.getMovieName().compare(movieName) == 0;
    });    
    return vector;
}

std::vector<Session> Cinema::findByTicketPrice(const double ticketPrice) {
    std::vector<Session> vector;
    std::copy_if(sessions.begin(), 
        sessions.end(), 
        std::back_inserter(vector), 
        [ticketPrice](Session session) {
            return session.getTicketPrice() == ticketPrice;
    });    
    return vector;
}

std::vector<Session> Cinema::findByStartTime(const time_t start) {
    std::vector<Session> vector;
     std::copy_if(sessions.begin(), 
        sessions.end(), 
        std::back_inserter(vector), 
        [start](Session session) {
            return session.getTimeRange().start == start;
    });   
    return vector;
}

std::vector<Session> Cinema::findByEndTime(const time_t end) {
    std::vector<Session> vector;
    std::copy_if(sessions.begin(), 
        sessions.end(), 
        std::back_inserter(vector), 
        [end](Session session) {
            return session.getTimeRange().end == end;
    });    
    return vector;
}
#pragma endregion finding

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