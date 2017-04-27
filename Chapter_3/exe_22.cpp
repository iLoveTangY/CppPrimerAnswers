#include <string>
#include <cctype>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main(void)
{
    vector<string> svec;
    string line;

    while(getline(std::cin, line) && !line.empty())
        svec.push_back(line);

    for(auto it = svec.begin(); it != svec.end() && !it->empty(); ++it)
        for(auto &c : (*it))
            c = toupper(c);

    for(auto it = svec.cbegin(); it != svec.cend() && !it->empty(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
