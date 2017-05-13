#include <iostream>
#include <deque>

using namespace std;

int main()
{
    string str;
    deque<string> deq;

    while(cin >> str)
        deq.push_back(str);

    for(auto beg = deq.begin(); beg != deq.end(); ++beg)
        cout << *beg << endl;

    return 0;
}
