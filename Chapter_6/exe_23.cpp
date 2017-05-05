#include <iostream>

using namespace std;

void print(const int *p)
{
    cout << *p << endl;
}

void print(const int *p, const int sz)
{
    int i = 0;
    while(i != sz)
    {
        cout << *p++ << endl;
        ++i;
    }
}

void print(const int *b, const int *e)
{
    for(auto q = b; q != e; ++q)
        cout << *q << endl;
}


int main()
{
    int i = 0, j[2] = {0, 1};

    print(&i);
    print(j);
    print(&i, 1);
    print(j, sizeof(j)/sizeof(*j));
    print(begin(j), end(j));

    return 0;
}
