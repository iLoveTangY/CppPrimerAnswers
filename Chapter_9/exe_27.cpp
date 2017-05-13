#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> flst = {1, 2, 3, 4, 5, 6};
    auto prev = flst.before_begin();
    auto curr = flst.begin();

    while(curr != flst.end())
    {
        if(*curr & 1)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for(auto i : flst)
        cout << i << ends;
    cout << endl;

    return 0;
}
