#include <iostream>
#include "cinema.hpp"

const int HOUR = 1'000 * 60 * 60;

void init(Cinema &cinema);
void showMenu();
void showAll(Cinema &cinema);
void showActive(Cinema &cinema);
void addElement(Cinema &cinema);
void serialize(Cinema &cinema);
void deserialize(Cinema &cinema);

int main(int argc, char** argv) {
    auto cinema = Cinema();
    char answer = '0';
    init(cinema);

    while (answer != 'e') {
        system("clear");
        showMenu();
        std::cin >> answer;

        switch (answer) {
            case '1':
                showAll(cinema);
                break;
            case '2':
                showActive(cinema);
                break;
            case '3':
                addElement(cinema);
                break;
            case '4':
                serialize(cinema);
                break;
            case '5':
                deserialize(cinema);
                break;
            default:
                break;
        }
        if (answer != 'e') {
            std::cout << "Press Enter to continue" << std::endl;
            std::cin.ignore(2147483647, '\n');
            std::cin.get();
        }
    }

    return EXIT_SUCCESS;
}

void init(Cinema &cinema) {
    Session session = Session(1, 1, "movie_1", 111, TimeRange(std::time(0) - 2 * HOUR, std::time(0) + 1 * HOUR));
    Session session2 = Session(2, 2, "movie_2", 222, TimeRange());
    Session session3 = Session(3, 3, "movie_3", 123, TimeRange(std::time(0), std::time(0) + 3 * HOUR));

    cinema.addSession(session);
    cinema.addSession(session2);
    cinema.addSession(session3);
}

void showMenu() {
    std::cout << "1. Show all sessions" << std::endl
        << "2. Show active" << std::endl
        << "3. Add session" << std::endl
        << "4. Save to file" << std::endl
        << "5. Read from file" << std::endl
        << "e. Exit" << std::endl
        << "option: ";
}

void showAll(Cinema &cinema) {
    std::cout << "All sessions:" << std::endl;
    for (Session session : cinema.getAllSessions()) 
        std::cout << session.toString() << std::endl;
}

void showActive(Cinema &cinema) {
    std::cout << "Active sessions:" << std::endl;
    for (Session session : cinema.getActiveSessions()) 
        std::cout << session.toString() << std::endl;
}

void addElement(Cinema &cinema) {
    int sessionNumber, hallNumber;
    std::string movieName;
    double ticketPrice;
    time_t start, end;

    std::cout << "Session number: ";
    std::cin >> sessionNumber;

    std::cout << "Hall number: ";
    std::cin >> hallNumber;

    std::cout << "Movie name: ";
    std::cin >> movieName;

    std::cout << "Ticket price: ";
    std::cin >> ticketPrice;

    std::cout << "Time start: ";
    std::cin >> start;

    std::cout << "Time end: ";
    std::cin >> end;

    cinema.addSession(Session(sessionNumber, hallNumber, movieName, ticketPrice, TimeRange(start, end)));
}

void serialize(Cinema &cinema) {
    std::string path;
    std::cout << "Enter file name: ";
    std::cin >> path;
    cinema.serialize(path);
}

void deserialize(Cinema &cinema) {
    std::string path;
    std::cout << "Enter file name: ";
    std::cin >> path;
    cinema.deserialize(path);
}