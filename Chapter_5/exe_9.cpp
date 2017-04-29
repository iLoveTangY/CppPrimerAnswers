#include <iostream>
#include <string>

using std::string;

int main(void)
{
    string word;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    while(std::cin >> word)
    {
        for(auto c : word)
        {
            if(c == 'a')
                ++aCnt;
            else if(c == 'e')
                ++eCnt;
            else if(c == 'i')
                ++iCnt;
            else if(c == 'o')
                ++oCnt;
            else if(c == 'u')
                ++uCnt;
        }
    }

    std::cout << "a: " << aCnt << std::endl;
    std::cout << "e: " << eCnt << std::endl;
    std::cout << "i: " << iCnt << std::endl;
    std::cout << "o: " << oCnt << std::endl;
    std::cout << "u: " << uCnt << std::endl;

    return 0;
}
