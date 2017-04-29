#include <iostream>
#include <string>

using std::string;

int main(void)
{
    string line;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, entCnt = 0;

    while(getline(std::cin, line))
    {
        for(auto c : line)
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
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++entCnt;
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
    std::cout << "<space>: " << spaceCnt << std::endl;
    std::cout << "<tab>: " << tabCnt << std::endl;
    std::cout << "<enter>: " << entCnt << std::endl;

    return 0;
}
