#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void test_and_insert(forward_list<string> &sflst, const string &s1, const string & s2)
{
    auto prev = sflst.before_begin();
    auto curr = sflst.begin();
    bool inserted = false;

    while(curr != sflst.end())
    {
        if(*curr == s1)
        {
            curr = sflst.insert_after(curr, s2);
            inserted = true;
        }
        else
        {
            prev = curr;
            curr++;
        }
    }
    if(!inserted)
        sflst.insert_after(prev, s2);
}

int main()
{
    forward_list<string> sflst = {"no", "project", "in", "no", "project"};

    test_and_insert(sflst, "no", "at");
    for(auto s : sflst)
        cout << s << ends;
    cout << endl;

    return 0;
}
