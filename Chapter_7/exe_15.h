#ifndef EXE_15
#define EXE_15

#include <string>

struct Person
{
    std::string _name;
    std::string _address;

    std::string getName() const { return name; }
    std::string getAddr() const { return address; }

    Person() = default;
    Person(const std::string &name, const std::string &address) :
        _name(name), _address(address) { }
    Person(std::istream &is)
    {
        read(is, *this);
    }
};

std::istream& read(std::istream&, Person&);
std::ostream& print(std::ostream&, const Person&);
#endif // EXE_15


