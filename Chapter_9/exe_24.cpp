#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;  //empty vector

    //The following codes are wrong.
    cout << vec.at(0);
    cout << vec[0];
    cout << vec.front();
    cout << *vec.begin();

    return 0;
}
