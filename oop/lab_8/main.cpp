#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

void inputVector(std::vector<std::wstring> &vector, std::wstring message = L"") {
    std::wcout << message;
    std::wcout << L"(use \\exit to exit)" << std::endl;
    std::wstring input;

    std::wcin >> input;
    while (input.compare(L"\\exit")) {
        vector.push_back(input);
        std::wcin >> input;
    }
    std::wcout << std::endl;
}

void sortVector(std::vector<std::wstring> &vector) {
    std::sort(vector.begin(), 
        vector.end(), 
        [](std::wstring name_1, std::wstring name_2) {
            return name_1.compare(name_2) < 0;
    });
}

void printVector(std::vector<std::wstring> &vector, std::wstring message = L"") {
    std::wcout << message;
    for (auto name : vector)
        std::wcout << name << std::endl;
}

int main() {
    auto mattFriends = std::vector<std::wstring>();
    auto patFriends = std::vector<std::wstring>();
    auto friends = std::vector<std::wstring>();

    inputVector(mattFriends, L"Enter Matt freinds\n");
    inputVector(patFriends, L"Enter Pat freinds\n");

    sortVector(mattFriends);
    sortVector(patFriends);
    
    printVector(mattFriends, L"Matt friends:\n");
    printVector(patFriends, L"Pat friends:\n");
        
    friends.insert(friends.end(), mattFriends.begin(), mattFriends.end());
    friends.insert(friends.end(), patFriends.begin(), patFriends.end());
    sortVector(friends);
    friends.erase(std::unique(friends.begin(), friends.end()), friends.end());
    printVector(friends, L"Friends:\n");

    return EXIT_SUCCESS;
}