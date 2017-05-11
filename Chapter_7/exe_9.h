#ifndef EXE_9
#define EXE_9

#include <string>

struct Person
{
    std::string name;
    std::string address;

    std::string getName() const { return name; }
    std::string getAddr() const { return address; }
};

std::istream& read(std::istream&, Person&);
std::ostream& print(std::ostream&, const Person&);
#endif // EXE_9

