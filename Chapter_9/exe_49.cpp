#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in("exe_49.cpp");
    string str, longestWord;
    int maxLength = 0;

    while(in >> str)
    {
        if(str.find_first_of("bdfghjklpqty") != string::npos)
            continue;
        cout << str << " ";
        if(maxLength < str.size())
        {
            maxLength = str.size();
            longestWord = str;
        }
    }

    cout << endl << "The longest word: " << longestWord << endl;

    return 0;
}
