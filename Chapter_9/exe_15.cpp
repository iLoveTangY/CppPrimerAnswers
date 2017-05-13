#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {1, 3, 5, 7};

    cout << boolalpha << (v1 == v2) << endl;

    return 0;
}
