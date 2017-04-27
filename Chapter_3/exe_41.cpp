#include <iostream>
#include <vector>

using std::vector;

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> iv(std::begin(a), std::end(a));

    for(auto i : iv)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
