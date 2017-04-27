#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;

int main(void)
{
    string line, word;

    while(getline(cin, line))
        cout << line << std::endl;

    while(cin >> word)
        cout << word << " ";

    cout << std::endl;

    return 0;
}
