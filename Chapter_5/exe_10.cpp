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
            switch(c)
            {
            case 'a': case 'A':
                ++aCnt;
                break;
            case 'e': case 'E':
                ++eCnt;
                break;
            case 'i': case 'I':
                ++iCnt;
                break;
            case 'o': case 'O':
                ++oCnt;
                break;
            case 'u': case 'U':
                ++uCnt;
                break;
            default:
                break;
            }
        }
    }

    std::cout << "a: " << aCnt << std::endl;
    std::cout << "e: " << eCnt << std::endl;
    std::cout << "i: " << iCnt << std::endl;
    std::cout << "o: " << oCnt << std::endl;
    std::cout << "u: " << uCnt << std::endl;

    return 0;
}
