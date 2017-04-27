#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void printIntVec(vector<int> ivec)
{
    for(auto it = ivec.cbegin(); it != ivec.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

void printStrVec(vector<string> svec)
{
    for(auto it = svec.cbegin(); it != svec.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main(void)
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    printIntVec(v1);
    printIntVec(v2);
    printIntVec(v3);
    printIntVec(v4);
    printIntVec(v5);
    printStrVec(v6);
    printStrVec(v7);

    return 0;
}

