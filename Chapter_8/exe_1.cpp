#include <iostream>
#include <stdexcept>

using namespace std;

istream& func(istream& in)
{
    int v;
    while(!in.eof())
    {
        in >> v;
        if(in.bad())
            throw runtime_error("IO error");
        if(in.fail())
        {
            cerr << "Data error, please input integer number." << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    cout << "Please input some integers(end by enter ctrl+z):";
    func(cin);

    return 0;
}
