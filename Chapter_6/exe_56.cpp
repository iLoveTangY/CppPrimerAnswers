#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if(b == 0)
        throw runtime_error("The second number can't be zero.");
    return a / b;
}

int compute(int a, int b, int (*p)(int, int))
{
    try
    {
        cout << p(a, b) << endl;
    }
    catch(runtime_error err)
    {
        cout << err.what() << endl;
    }
}

int main()
{
    int i = 5, j = 10;
    decltype(add) *p1 = add, *p2 = subtraction, *p3 = mul, *p4 = divide;
    vector<decltype(add) *> vF = {p1, p2, p3, p4};

    for(auto p : vF)
        compute(i, j, p);

    return 0;
}
