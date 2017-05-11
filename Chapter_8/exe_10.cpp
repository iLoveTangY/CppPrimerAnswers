#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("outfile.txt");
    string line, word;
    vector<string> svec;
    while(getline(in, line))
        svec.push_back(line);

    for(auto line : svec)
    {
        istringstream iss(line);
        while(iss >> word)
            cout << word << ends;
    }
    return 0;
}
