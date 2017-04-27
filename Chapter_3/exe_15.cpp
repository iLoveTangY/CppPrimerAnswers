#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;

int main(void)
{
    vector<string> ivec;
    string str;

    while(std::cin >> str)
        ivec.push_back(str);

    for(auto s : ivec)
        std::cout << s << " ";

    std::cout << std::endl;

    return 0;
}

