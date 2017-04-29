#include <string>
#include <iostream>
#include <cctype>

using std::string;

int main(void)
{
    bool flag = false;
    string word, pre;

    while(std::cin >> word)
    {
        if(!isupper(word[0]))
            continue;
        if(word == pre)
        {
            flag = true;
            break;
        }
        else
            pre = word;
    }

    if(flag)
        std::cout << word << " was repeated." << std::endl;
    else
        std::cout << "No word was repeated." << std::endl;

    return 0;
}
