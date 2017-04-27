#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    int ia[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    //version 1
    for(const auto &row : ia)
    {
        for(auto col : row)
            cout << col << " ";
        cout << endl;
    }

    //version 2
    for(size_t i = 0; i < 3; ++i)
    {
        for(size_t j = 0; j < 4; ++j)
            cout << ia[i][j] << " ";
        cout << endl;
    }

    //version 3
    for(int (*p)[4] = ia; p != ia+3; p++)
    {
        for(int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
        cout << endl;
    }

    return 0;
}
