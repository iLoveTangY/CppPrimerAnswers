#include <iostream>
#include <vector>

using std::vector;

int main(void)
{
    vector<int> vec = {1, 2, 3, 4, 5};
    int a[5];
    size_t index = 0;
    for(auto i : vec)
        a[index++] = i;

    for(auto i : a)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
