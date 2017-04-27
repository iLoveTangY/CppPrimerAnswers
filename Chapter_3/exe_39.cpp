#include <cstring>
#include <string>
#include <iostream>

using std::string;

int main(void)
{
    string s1("hello world"), s2("hello World");
    const char ca[] = "Hello world";
    const char cb[] = "Hello world";

    std::cout << (s1 == s2) << std::endl;
    std::cout << (strcmp(ca, cb) == 0 ? true : false) << std::endl;

    return 0;
}
