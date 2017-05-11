#include "exe_15.h"

std::istream& read(std::istream &is, Person &p)
{
    is >> p._name >> p._address;

    return is;
}

std::ostream& print(std::ostream &os, const Person &p)
{
    os << p._name << ": " << p._address;

    return os;
}

