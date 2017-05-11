#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

string format(const string &s)
{
    return s;
}

bool valid(const string &s)
{
    return true;
}

int main(int argc, char **argv)
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    if(argc != 2)
    {
        cerr << "Please give a file name." << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if(!in)
    {
        cerr << "Can't open file." << endl;
        return -1;
    }

    while(getline(in, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    ostringstream os;
    for(const auto &entry: people)
    {
        ostringstream formatted, badNums;
        for(const auto &nums : entry.phones)
        {
            if(!valid(nums))
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        }
        if(badNums.str().empty())
            os << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                << "invalid number(s) " << badNums.str() << endl;
    }
    cout << os.str() << endl;

    return 0;
}

