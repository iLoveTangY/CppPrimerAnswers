#ifndef EXE_22
#define EXE_22

#include <string>

class Person
{
    friend std::istream& read(std::istream&, Person&);
    friend std::ostream& print(std::ostream&, const Person&);

private:
    std::string _name;
    std::string _address;

public:
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
#endif // EXE_22



