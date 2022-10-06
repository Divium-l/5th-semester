#include "emp.hpp"

using namespace std;

#pragma region abstr_emp
abstr_emp::abstr_emp() {
    fname = "";
    lname = "";
    job = "";
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j) {
    fname = fn;
    lname = ln;
    job = j;
}

void abstr_emp::ShowAll() const {
    cout << "fname: " << fname << endl
        << "lname: " << lname << endl
        << "job: " << job << endl;
}

void abstr_emp::SetAll() {
    fname = "undefined";
    lname = "undefined";
    job = "undefined";
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e) {
    os << "fname: " << e.fname << endl
        << "lname: " << e.lname << endl
        << "job: " << e.job << endl;
    
    return os;
}
#pragma endregion abstr_emp

#pragma region employee
employee::employee() : abstr_emp() {}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const { 
    abstr_emp::ShowAll(); 
}

void employee::SetAll() {
    abstr_emp::SetAll();
}
#pragma endregion employee

#pragma region manager
manager::manager() : abstr_emp() {
    inchargeof = 0;
}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico) : abstr_emp(fn, ln, j) {
    inchargeof = ico;
}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e) {
    inchargeof = ico;
}
manager::manager(const manager & m) : abstr_emp(m) {
    inchargeof = m.inchargeof;
}
void manager::ShowAll() const {
    abstr_emp::ShowAll();
    cout << "inchargeof: " << inchargeof << endl;
}
void manager::SetAll() {
    abstr_emp::SetAll();
    inchargeof = 0;
}
#pragma endregion manager

#pragma region fink
fink::fink() : abstr_emp() {}
fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) : 
        abstr_emp(fn, ln, j) {
    reportsto = rpo;
}
fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e) {
    reportsto = rpo;
}
fink::fink(const fink & e) : abstr_emp(e) {
    reportsto = e.reportsto;
}
void fink::ShowAll() const {
    abstr_emp::ShowAll();
    cout << "reportsto: " << reportsto << endl;
}
void fink::SetAll() {
    abstr_emp::SetAll();
    reportsto = "undefined";
}
#pragma endregion fink

#pragma region highfink
highfink::highfink() : abstr_emp() {
    InChargeOf() = 0;
    ReportsTo() = "";
}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico) :
    abstr_emp(fn, ln, j) {
    InChargeOf() = ico;
    ReportsTo() = rpo;
}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : abstr_emp(e) {
    InChargeOf() = ico;
    ReportsTo() = rpo;
}

highfink::highfink(const fink & f, int ico) : abstr_emp(f) {
    InChargeOf() = ico;
    ReportsTo() = "";
}

highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m) {
    InChargeOf() = 0;
    ReportsTo() = rpo;
}

highfink::highfink(const highfink & h) : abstr_emp(h) {
    InChargeOf() = h.InChargeOf();
    ReportsTo() = h.ReportsTo();
}

void highfink::ShowAll() const {
    abstr_emp::ShowAll();
    cout << "reportsto: " << ReportsTo() << endl;
    cout << "inchargeof: " << InChargeOf() << endl;
}

void highfink::SetAll() {
    manager::SetAll();
    fink::SetAll();
}
#pragma endregion highfink
