#include <iostream>
#include <vector>

using std::vector;

int main(void)
{
    vector<int> ivec;
    int num;

    while(std::cin >> num)
        ivec.push_back(num);

    for(auto it = ivec.begin(); it != (ivec.end() - 1); ++it)
        std::cout << *it + *(it+1) << " ";
    std::cout << std::endl;

    for(auto beg = ivec.begin(), end = ivec.end()-1; beg < end; ++beg, --end)
        std::cout << *beg + *end << " ";
    std::cout << std::endl;

    return 0;
}
