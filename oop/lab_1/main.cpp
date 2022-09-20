#include <iostream>
#define UNDEFINED_STRING "undefined"

using namespace std;

class Cow
{
    private:
        char* name;
        char* hobby;
        double weight;
    public:
        Cow();
        Cow(const char* name, const char* hobby, double weight);
        Cow(const Cow& cow);
        ~Cow();
        Cow& operator=(const Cow& cow);
        void showCow(void) const;
};

Cow::Cow()
{
    int size = strlen(UNDEFINED_STRING);
    name = new char[size];
    hobby = new char[size];
    strcpy(name, UNDEFINED_STRING);
    strcpy(hobby, UNDEFINED_STRING);
    weight = 0.0;
}

Cow::Cow(const char* name, const char* hobby, double weight)
{
    int stringSize = strlen(name);
    this->name = new char[stringSize];
    strcpy(this->name, name);

    stringSize = strlen(hobby);
    this->hobby = new char[stringSize];
    strcpy(this->hobby, hobby);

    this->weight = weight;
}

Cow::Cow(const Cow& cow)
{
    name = new char[strlen(cow.name)];
    strcpy(name, cow.name);

    hobby = new char[strlen(cow.hobby)];
    strcpy(hobby, cow.hobby);
    
    weight = cow.weight;
}

Cow::~Cow()
{
    if (name != nullptr)
        delete[] name;

    if (hobby != nullptr) 
        delete[] hobby;
}

void Cow::showCow(void) const
{
    cout << "{" << "Name: " << name << ", ";
    cout << "Hobby: " << hobby << ", ";
    cout << "Weight: " << weight << "}";
}

Cow& Cow::operator=(const Cow& cow)
{
    if (&cow == this)
        return *this;

    delete[] name;
    name = new char[strlen(cow.name)];
    strcpy(name, cow.name);

    delete[] hobby;
    hobby = new char[strlen(cow.hobby)];
    strcpy(hobby, cow.hobby);
    
    weight = cow.weight;

    return *this;
}

int main()
{
    Cow cow_1 = Cow("Cow 1", "Hobby 1", 128.0);
    cow_1.showCow();
    cout << endl;

    Cow cow_2 = Cow("Cow 2", "Hobby 2", 256.0);
    cow_2.showCow();
    cout << endl;

    Cow cow_3 = Cow();
    cow_3.showCow();
    cout << endl;

    cow_1 = cow_2;
    cow_1.showCow();
    cout << endl;

    return 0;
}