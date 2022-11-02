#include <iostream>
#include "session.hpp"

int main(int argc, char** argv) {
    Session session = Session(1, 1, "movie 1", 123, SessionTime(100, 1000));
    Session session2 = Session(1, 1, "movie 1", 123, SessionTime());

    std::cout << "Session 1: " << session.toString() << std::endl;
    std::cout << "Session 2: " << session2.toString() << std::endl;

    return 0;
}