#include <vector>
#include <iostream>

using std::vector;

int main(void)
{
    vector<unsigned> scores(11, 0);
    unsigned grade;

    auto it = scores.begin();

    while(std::cin >> grade)
    {
        if(grade <= 100)
            ++(*(it + grade/10));
    }

    for(auto i : scores)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
