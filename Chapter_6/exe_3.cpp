#include <iostream>

int fact(int val);

int main()
{
    int i = 5;
    std::cout << i << "! = " << fact(i) << std::endl;

    return 0;
}

int fact(int val)
{
    int ret = 1;

    while(val > 1)
        ret *= val--;

    return ret;
}
