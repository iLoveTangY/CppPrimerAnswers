#include <string>
#include <iostream>

using namespace std;

void name_string(string &name, const string &prefix, const string &suffix)
{
    name.insert(0, " ");
    name.insert(0, prefix);
    name.insert(name.size(), " ");
    name.insert(name.size(), suffix);
}

int main()
{
    string s = "James Bond";
    name_string(s, "Mr.", "II");
    cout << s << endl;

    s = "M";
    name_string(s, "Mrs.", "III");
    cout << s << endl;

    return 0;
}

