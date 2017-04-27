#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    string str;
    cin >> str;

    for(auto &x : str)
        x = 'X';

    cout << str << endl;

    return 0;
}
