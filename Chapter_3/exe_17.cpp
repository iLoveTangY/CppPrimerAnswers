#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::vector;
using std::string;


int main(void)
{
    string word;
    vector<string> vec;

    while(std::cin >> word)
        vec.push_back(word);
    for(auto &w : vec)
        for(auto &c : w)
            c = toupper(c);

    for(auto w : vec)
        std::cout << w << std::endl;

    return 0;
}
