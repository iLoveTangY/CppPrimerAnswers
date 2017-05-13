#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "ab2c3d7r4e6";
    string numbers = "0123456789";

    string::size_type pos = 0;
    while((pos = str.find_first_of(numbers, pos)) !=  string::npos)
    {
        cout << "found number at index: " << pos
             << " element is " << str[pos] << endl;
        ++pos;
    }

    pos = 0;
    while((pos = str.find_first_not_of(numbers, pos)) != string::npos)
    {
        cout << "found character at index: " << pos
             << " element is " << str[pos] << endl;
        ++pos;
    }

    return 0;
}
