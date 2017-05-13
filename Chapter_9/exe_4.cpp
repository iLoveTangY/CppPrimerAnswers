#include <vector>
#include <iostream>

using namespace std;

bool func(vector<int>::iterator b, vector<int>::iterator e, int i)
{
    while(b != e)
        if(*b++ == i)
            return true;

    return false;
}

int main()
{
    vector<int> vec = {1, 3, 5, 2, 9};

    cout << boolalpha << func(vec.begin(), vec.end(), 7) << endl;

    return 0;
}
