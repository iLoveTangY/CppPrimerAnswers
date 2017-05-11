#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vStr;
    ifstream in("exe_1.cpp");
    string str;

    while(getline(in, str))
        vStr.push_back(str);

    for(auto s : vStr)
        cout << s << endl;

    return 0;
}
