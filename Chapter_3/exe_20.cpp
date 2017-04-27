#include <vector>
#include <iostream>

using std::vector;

int main(void)
{
    int num;
    vector<int> ivec;

    while(std::cin >> num)
        ivec.push_back(num);
    for(decltype(ivec.size()) index = 0; index < ivec.size()-1; index += 2)
        std::cout << ivec[index] + ivec[index+1] << " ";
    std::cout << std::endl;

    decltype(ivec.size()) beg = 0, end = ivec.size() - 1;
    while(beg < end)
        std::cout << ivec[beg++] + ivec[end--] << " ";
    std::cout << std::endl;

    return 0;
}
