#include <iostream>
#include <vector>

using std::vector;

bool IsEqualVec(vector<int> va, vector<int> vb)
{
    return va == vb;
}

bool IsEqualArray(int a[], int b[], size_t sz)
{
    bool flag = true;

    for(int *first = a, *second = b; first < a+sz, second < b+sz; ++first, ++second)
        if(*first != *second)
            flag = false;

    return flag;
}

int main(void)
{
    vector<int> va = {1, 2, 3 ,4 , 5}, vb = {1, 3, 5, 5, 9};
    constexpr size_t sz = 4;
    int a[sz] = {1, 2, 3, 4};
    int b[sz] = {1, 2, 3, 4};

    std::cout << std::boolalpha << IsEqualVec(va, vb) << std::endl;
    std::cout << std::boolalpha << IsEqualArray(a, b, sz) << std::endl;

    return 0;
}
