#include <vector>
#include <iostream>

using namespace std;

vector<int>::iterator func(vector<int>::iterator b, vector<int>::iterator e, int i)
{
    while(b != e)
        if(*b++ == i)
            return --b;

    return b;
}

int main()
{
    vector<int> vec = {1, 3, 5, 2, 9};

    auto it = func(vec.begin(), vec.end(), 7);
    if(it == vec.end())
        cout << "Not found" << endl;
    else
        cout << "Found " << *it << endl;

    return 0;
}

