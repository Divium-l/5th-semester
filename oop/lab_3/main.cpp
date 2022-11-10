#include <iostream>
#include <cstring>

using namespace std;

template<typename T> T maxn(T* arr, const size_t size);
template<> const char* maxn<const char*>(const char** arr, const size_t size);

int main() {
    auto s = std::string("11");
    int intArray[] = {6, 5, 0, -4, 2, 1};
    double doubleArray[] = {5.0, 5.1, 0.0, -4.0};
    const char* charPtrArray[] = {"str", "very long str", "VERY LONG STR", "short str", "5th"};

    cout << "Max int = " << maxn<>(intArray, 6) << endl;
    cout << "Max double = " << maxn<>(doubleArray, 4) << endl;
    cout << "Longest string = " << maxn(charPtrArray, 5) << endl;

    return EXIT_SUCCESS;
}

template<typename T> T maxn(T* arr, const size_t size) {
    T max = arr[0];
    for (size_t i = 1; i < size; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}

template<> const char* maxn<const char*>(const char** arr, const size_t size) {
    size_t maxLength = strlen(arr[0]);
    const char* maxString = arr[0];
    for (size_t i = 1; i < size; i++) {
        size_t length = strlen(arr[i]);
        if (maxLength < length) {
            maxLength = length;
            maxString = arr[i];
        }
    }
    return maxString;
}


