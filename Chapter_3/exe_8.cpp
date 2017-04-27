#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    string str, str2;

    cin >> str;
    str2 = str;

    decltype(str.size()) index = 0;

    while(index != str.size())
    {
        str[index] = 'X';
        ++index;
    }

    for(index = 0; index != str2.size(); ++index)
        str2[index] = 'X';

    cout << str << endl;
    cout << str2 << endl;

    return 0;
}
