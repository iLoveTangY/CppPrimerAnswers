#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> lstInt = {1, 2, 3, 4};
    vector<double> vecDou(lstInt.begin(), lstInt.end());
    for(const auto i : vecDou)
        cout << i << ends;
    cout << endl;

    vector<int> vecInt = {5, 6, 7, 8};
    vector<double> vecDou2(vecInt.begin(), vecInt.end());
    for(const auto i : vecDou2)
        cout << i << ends;
    cout << endl;

    return 0;
}
