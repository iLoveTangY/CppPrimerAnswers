#include <iostream>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> lst)
{
    int ret = 0;

    for(const auto i : lst)
        ret += i;

    return ret;
}

int main()
{
    cout << sum({1, 2, 3, 4, 5}) << endl;

    return 0;
}
