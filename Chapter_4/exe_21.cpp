#include <iostream>
#include <vector>

using std::vector;

int main(void)
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8};

    for(auto &i : ivec)
        i = (i % 2) ? 2*i : i;

    for(auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
