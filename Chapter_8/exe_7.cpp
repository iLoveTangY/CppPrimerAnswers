#include "../Chapter_7/exe_26.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        cerr << "Plz give two files name." << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if(!in)
    {
        cerr << "Can't open file." << endl;
        return -1;
    }
    ofstream out(argv[2], ofstream::app);  //追加模式，下一题要求

    Sales_data total;
    if(read(in, total))
    {
        Sales_data trans;
        while(read(in, trans))
        {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else
        cerr << "No data." << endl;

    return 0;
}

