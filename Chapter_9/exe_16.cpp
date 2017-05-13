#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool isEqual(list<int> lst, vector<int> vec)
{
    if(lst.size() != vec.size())
        return false;
    auto lb = lst.begin(), le = lst.end();
    auto vb = vec.begin(), ve = vec.end();
    while(lb != le)
        if(*lb++ != *vb++)
            return false;
    return true;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    list<int> lst = {1, 3, 3, 4};

    cout << boolalpha << isEqual(lst, vec) << endl;

    return 0;
}
