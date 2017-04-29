#include <iostream>
#include <string>

using std::string;

int main(void)
{
    string str1, str2, rsp;

    do
    {
        std::cout << "Please enter tow string: " << std::endl;
        std::cin >> str1 >> str2;
        std::cout << ((str1.size() < str2.size()) ? str1 : str2) << std::endl;
        std::cout << "More? Enter yes or no: ";
        std::cin >> rsp;
    }while(!rsp.empty() && rsp[0] != 'n');

    return 0;
}
