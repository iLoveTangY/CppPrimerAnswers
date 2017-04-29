#include <iostream>
#include <string>

using std::string;

int main(void)
{
    int ffCnt = 0, flCnt = 0, fiCnt = 0;
    bool preIsF = false;
    string line;

    while(getline(std::cin, line))
    {
        for(auto c : line)
        {
            if(c == 'f')
                if(preIsF)
                    ++ffCnt;
                else
                    preIsF = true;
            else if(preIsF)
            {
                switch(c)
                {
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
                default:
                    break;
                }
                preIsF = false;
            }

        }
    }

    std::cout << "ff: " << ffCnt << std::endl;
    std::cout << "fl: " << flCnt << std::endl;
    std::cout << "fi: " << fiCnt << std::endl;

    return 0;
}
