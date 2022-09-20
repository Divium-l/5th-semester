## Instructions

Имеется следующее объявление класса

```c++
class Cow
{
  private:
    char *name;
    char *hobby;
    double weight;
  public:
    Cow();
    Cow(const char * nm, const char*ho, double weight);
    Cow(const Cow &c);
    ~Cow();
    Cow &operator=(const Cow &c);
    void ShowCow() const;
};
```

Реализовать класс. Сделать динамическое выделение памяти для строк.