#include <iostream>
#include <string>
#include <vector>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
     for (auto beg = s.begin(); std::distance(beg, s.end()) >=
                               std::distance(oldVal.begin(), oldVal.end());)
    {
        if (string(beg, beg + oldVal.size()) == oldVal)
        {
            beg = s.erase(beg, beg + oldVal.size());
            beg = s.insert(beg, newVal.cbegin(), newVal.cend());
            std::advance(beg, newVal.size());
        }
        else
            ++beg;
    }
}

int main()
{
    string s = "tho thru tho!";
    replace_string(s, "thru", "through");
    cout << s << endl;

    replace_string(s, "tho", "though");
    cout << s << endl;

    return 0;
}
