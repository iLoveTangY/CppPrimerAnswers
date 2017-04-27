#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    string word, ret;

    while(cin >> word)
        ret = ret + word + " ";

    cout << ret << endl;

    return 0;
}
