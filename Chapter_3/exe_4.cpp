#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

int main(void)
{
    string first, second;

    getline(cin, first);
    getline(cin, second);

    bool ret = (first == second);
    cout << boolalpha << ret << endl;
    if(!ret)
        cout << ((first > second) ? first : second) << endl;

    ret = (first.size() == second.size());
    cout << boolalpha << ret << endl;
    if(!ret)
        cout << ((first.size() > second.size()) ? first : second) << endl;

    return 0;
}
