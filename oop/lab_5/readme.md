## instructions

```c++
// emp.h -- заголовочный файл для класса abstr_emp и его дочерних классов 
#include <iostream>
#include <string>

class abstr_emp {
private:
	std::string fname; std::string lname ; std::string job;
public: 
    abstr_emp() ;
	abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
	virtual void ShowAll() const;
	virtual void SetAll();
	friend std::ostream & operator<< (std::ostream & os, const abstr_emp & e);
	virtual ~abstr_emp() = 0;
};

// виртуальный базовый класс
class employee : public abstr_emp {
public:
	employee();
	employee(const std::string & fn, const std::string & ln,
	    const std::string & j);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class manager : virtual public abstr_emp {
private:
	int inchargeof; // количество управляемых abstr_emp
protected:
	int InChargeOf() const { return inchargeof ; }
	int & InChargeOf() { return inchargeof; }
public:
    manager();
	manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0) ;
	manager(const abstr_emp & e, int ico);
    manager(const manager & m);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class fink : virtual public abstr_emp {
private:
	std::string reportsto;
protected:
	const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo () { return reportsto; }
public:
	fink();
	fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo);
	fink(const abstr_emp & e, const std::string & rpo); 
    fink(const fink & e);
	virtual void ShowAll() const;
	virtual void SetAll();
};

// надзор за управляющими
class highfink : public manager, public fink {
public:
	highfink();
	highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico);
	highfink(const abstr_emp & e, const std::string & rpo, int ico); 
    highfink(const fink & f, int ico);
	highfink(const manager & m, const std::string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
};
```

Здесь в иерархии классов используется множественное наследование с вирту­альным базовым классом. Поэтому не забывайте о специальных правилах для списков инициализации в конструкторах. Обратите также внимание на наличие нескольких методов с защищенным доступом. Это упрощает код некоторых ме­тодов highfink. (Например, если метод highfink::ShowAll() просто вызывает fink::ShowAll() и manager::ShowAll() , то это приводит к двукратному вы­зову abstr_emp::ShowAll(). Реализуйте эти методы и протестируйте классы.