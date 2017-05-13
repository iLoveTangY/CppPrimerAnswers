#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main()
{
    list<int> lst = {1, 2, 3, 4, 5, 6, 7};
    deque<int> odd, even;

    for(auto i : lst)
        if(i & 1)
            odd.push_back(i);
        else
            even.push_back(i);

    cout << "odd numbers: ";
    for(auto i : odd)
        cout << i << ends;
    cout << endl;

    cout << "even numbers: ";
    for(auto i : even)
        cout << i << ends;
    cout << endl;

    return 0;
}
