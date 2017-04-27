#include <iostream>
#include <vector>

using std::vector;

int main(void)
{
    int a[10];

    for(size_t index = 0; index < 10; ++index)
        a[index] = index;

    for(auto i : a)
        std::cout << i << " ";
    std::cout << std::endl;

    int b[10];

    for(size_t index = 0; index < 10; ++index)
        b[index] = a[index];
    for(auto i : a)
        std::cout << i << " ";
    std::cout << std::endl;

    vector<int> va, vb;
    int cnt = 0;

    while(cnt < 10)
        va.push_back(cnt++);
    vb = va;

    for(auto i : va)
        std::cout << i << " ";
    std::cout << std::endl;

    for(auto i : vb)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
