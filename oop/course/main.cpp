/*
1. + Создать класс элементов заданной структуры.

2. ! Работа программы осуществляется с помощью главного меню.

3. Предусмотреть ввод элементов класса, производить проверку корректности ввода

4. + Предусмотреть сохранение введенных данных заданной структуры в файл, а также считывание данных из файла.

5. + Предусмотреть сортировку элементов класса по выбранному параметру

6. + Предусмотреть поиск определенного элемента класса по заданному параметру и вывод всех параметров 
данного элемента на экран.

7. Предусмотреть редактирование выбранного элемента класса.

Структура элементов определяется номером Вашего Варианта. 
Индивидуальный запрос формируется выбором нужной информации (например, № палаты) из 
выпадающего списка данных, который формируется автоматически при считывании (заполнении) информации. 
Т.е. ответом на такой запрос не может быть пустой список.

№ сеанса, № зала, Наименование фильма, стоимость билета. 
Каждому номеру сеанса соответствует определенное время показа. 
Предусмотреть это в виде отдельного класса элементов с соответствующим параметром. 
Выводить список фильмов с указанием номера зала, идущих сейчас( в данный час) в кинотеатре.
*/

#include <iostream>
#include "cinema.hpp"

const int HOUR = 1'000 * 60 * 60;

void init(Cinema &cinema);
void showMenu();
void showAll(Cinema &cinema);
void showActive(Cinema &cinema);

enum Option {
    SESSION_NUMBER = 1,
    HALL_NUMBER = 2,
    MOVIE_NAME = 3,
    TICKET_PRICE = 4,
    START_TIME = 5,
    END_TIME = 6,
    EXIT = 'e' - '0'
};

// utils
int inputInt() {
    int num;

    while (!(std::cin >> num)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect input. Please try again." << std::endl;
    }

    return num; 
}

double inputDouble() {
    double num;

    while (!(std::cin >> num)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect input. Please try again." << std::endl;
    }

    return num; 
}

std::string inputString() {
    std::string str;

    while (!(std::cin >> str)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect input. Please try again." << std::endl;
    }

    return str; 
}

time_t inputTime() {
    time_t num;

    while (!(std::cin >> num)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect input. Please try again." << std::endl;
    }

    return num; 
}

void printSessions(std::vector<Session> &sessions);
void unknownOption();
void pressEnterToCont();
// utils end

// sorting
void showSortMenu();
void sort(Cinema &cinema);
// sorting end

// finding
void showFindMenu() {
    std::cout << "1. Find by session number" << std::endl
        << "2. Find by hall number" << std::endl
        << "3. Find by movie name" << std::endl
        << "4. Find by ticket price" << std::endl
        << "5. Find by start time" << std::endl
        << "6. Find by end time" << std::endl
        << "e. Go back" << std::endl
        << "option: ";
}

void find(Cinema &cinema) {
    char answer = '0';

    while (answer != 'e') {
        system("clear");
        showFindMenu();
        std::vector<Session> foundSessions;
        std::cin >> answer;
        Option option = static_cast<Option>(answer - '0');

        switch (option) {
            case Option::SESSION_NUMBER: {
                auto sessionNumber = inputInt();
                foundSessions = cinema.findBySessionNumber(sessionNumber);
                break;
            }
            case Option::HALL_NUMBER: {
                auto hallNumber = inputInt();
                foundSessions = cinema.findByHallNumber(hallNumber);
                break;
            }
            case Option::MOVIE_NAME: {
                auto movieName = inputString();
                foundSessions = cinema.findByMovieName(movieName);
                break;
            }
            case Option::TICKET_PRICE: {
                auto ticketPrice = inputDouble();
                foundSessions = cinema.findByTicketPrice(ticketPrice);
                break;
            }
            case Option::START_TIME: {
                auto start = inputTime();
                foundSessions = cinema.findByStartTime(start);
                break;
            }
            case Option::END_TIME: {
                auto end = inputTime();
                foundSessions = cinema.findByEndTime(end);
                break;
            }
            case Option::EXIT:
                break;
            default:
                unknownOption();
                break;
        }
        if (answer != 'e') {
            printSessions(foundSessions);
            pressEnterToCont();
        }
    }
}
// finding end

void addElement(Cinema &cinema);
void serialize(Cinema &cinema);
void deserialize(Cinema &cinema);

int main() {
    auto cinema = Cinema();
    char answer = '0';
    init(cinema);

    while (answer != 'e') {
        system("clear");

        bool enteredSubMenu = false;
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
            case '6':
                enteredSubMenu = true;
                sort(cinema);
                break;
            case '7':
                enteredSubMenu = true;
                find(cinema);
                break;
            default:
                break;
        }
        if (!enteredSubMenu)
            if (answer != 'e')
                pressEnterToCont();
    }

    system("clear");
    return EXIT_SUCCESS;
}

#pragma region utils
void printSessions(std::vector<Session> &sessions) {
    for (auto session : sessions) 
        std::cout << session.toString() << std::endl;
}

void unknownOption() {
    std::cout << "Unknown option. Please try again." << std::endl;
}

void pressEnterToCont() {
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(2147483647, '\n');
    std::cin.get();
}
#pragma endregion utils

#pragma region sort
void showSortMenu() {
    std::cout << "1. Sort by session number" << std::endl
        << "2. Sort by hall number" << std::endl
        << "3. Sort by movie name" << std::endl
        << "4. Sort by ticket price" << std::endl
        << "5. Sort by start time" << std::endl
        << "6. Sort by end time" << std::endl
        << "e. Go back" << std::endl
        << "option: ";
}

void sort(Cinema &cinema) {
    char answer = '0';

    while (answer != 'e') {
        system("clear");
        showSortMenu();
        std::vector<Session> sortedSessions;
        std::cin >> answer;
        Option sortBy = static_cast<Option>(answer - '0');

        switch (sortBy) {
            case Option::SESSION_NUMBER:
                sortedSessions = cinema.sortBySessionNumber();
                break;
            case Option::HALL_NUMBER:
                sortedSessions = cinema.sortByHallNumber();
                break;
            case Option::MOVIE_NAME:
                sortedSessions = cinema.sortByMovieName();
                break;
            case Option::TICKET_PRICE:
                sortedSessions = cinema.sortByTicketPrice();
                break;
            case Option::START_TIME:
                sortedSessions = cinema.sortByStartTime();
                break;
            case Option::END_TIME:
                sortedSessions = cinema.sortByEndTime();
                break;
            case Option::EXIT:
                break;
            default:
                unknownOption();
                break;
        }
        if (answer != 'e') {
            printSessions(sortedSessions);
            pressEnterToCont();
        }
    }
}
#pragma endregion sort

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
        << "6. Sort" << std::endl
        << "7. Find" << std::endl
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