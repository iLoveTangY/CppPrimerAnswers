#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec(begin(ia), end(ia));
    list<int> lst(begin(ia), end(ia));

    auto it = vec.begin();
    while(it != vec.end())
        if(*it & 1)
            ++it;
        else
            it = vec.erase(it);  //É¾³ıÅ¼ÊıÔªËØ

    auto it2 = lst.begin();
    while(it2 != lst.end())
        if(*it2 & 1)
            it2 = lst.erase(it2);  //É¾³ıÆæÊıÔªËØ
        else
            ++it2;

    for(auto i : vec)
        cout << i << ends;
    cout << endl;

    for(auto i : lst)
        cout << i << ends;
    cout << endl;

    return 0;
}
