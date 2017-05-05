#include <iostream>

using namespace std;

bool HasUpper(const string &s)
{
    for(auto c : s)
        if(isupper(c))
            return true;

    return false;
}

void ToLower(string &s)
{
    for(auto &c : s)
        c = tolower(c);
}

int main()
{
    cout << "Please enter a string: ";
    string str;
    cin >> str;
    if(HasUpper(str))
    {
        ToLower(str);
        cout << "After change: " << str << endl;
    }
    else
        cout << "No upper case in " << str << endl;

    return 0;
}
