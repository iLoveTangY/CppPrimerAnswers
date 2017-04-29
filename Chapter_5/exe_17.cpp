#include <iostream>
#include <vector>

using std::vector;

int main(void)
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};

    decltype(v1.size()) sz = (v1.size() < v2.size()) ? v1.size() : v2.size();

    for(decltype(v1.size()) i = 0; i != sz; ++i)
        if(v1[i] != v2[i])
        {
            std::cout << "false" << std::endl;
            return 0;
        }
    std::cout << "true" << std::endl;

    return 0;
}
