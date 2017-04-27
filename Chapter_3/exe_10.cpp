#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    string line;
    getline(cin, line);

    for(auto &c : line)
        if(!ispunct(c))
            cout << c;

    return 0;
}
