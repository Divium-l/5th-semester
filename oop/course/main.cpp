#include <iostream>
#include "cinema.hpp"

const int HOUR = 1'000 * 60 * 60;

int main(int argc, char** argv) {
    Session session = Session(1, 1, "movie 1", 111, TimeRange(std::time(0) - 2 * HOUR, std::time(0) + 1 * HOUR));
    Session session2 = Session(2, 2, "movie 2", 222, TimeRange());
    Session session3 = Session(3, 3, "movie 3", 123, TimeRange(std::time(0), std::time(0) + 3 * HOUR));

    Cinema cinema = Cinema();
    cinema.addSession(session);
    cinema.addSession(session2);
    auto active = cinema.getActiveSessions();

    std::cout << std::time(0) << std::endl; 
    for (Session session : active) 
        std::cout << "Active sessions: " << session.toString() << std::endl;

    return EXIT_SUCCESS;
}