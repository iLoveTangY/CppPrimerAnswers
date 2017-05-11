#ifndef EXE_4
#define EXE_4

#include <string>

class Person
{
private:
    std::string name;
    std::string address;

public:
    std::string getName() const { return name; }
    std::string getAddr() const { return address; }
};
#endif // EXE_4
