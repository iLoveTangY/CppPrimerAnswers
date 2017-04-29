#include <string>
#include <iostream>

using std::string;

int main(void)
{
    int maxRepeat = 1, currRepeat = 1;
    string repeatWord = "", pre = "", currWord;

    while(std::cin >> currWord)
    {
        if(pre == currWord)
        {
            ++currRepeat;
        }
        else
        {
            currRepeat = 1;
            pre = currWord;
        }
        if(maxRepeat < currRepeat)
        {
            repeatWord = pre;
            maxRepeat = currRepeat;
        }
    }

    std::cout << repeatWord  << " was repeated " << maxRepeat << " times" << std::endl;

    return 0;
}
