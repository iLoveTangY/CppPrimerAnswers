#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vecStr = {"3", "5", "2"};
    int sum = 0;
    for(const auto &str : vecStr)
        sum += stoi(str);

    cout << "The sum is " << sum << endl;

    return 0;
}
