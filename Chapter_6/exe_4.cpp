#include <iostream>

int fact(int val)
{
    int ret = 1;

    while(val > 1)
        ret *= val--;

    return ret;
}

int getFact()
{
    std::cout << "Plz enter a number: ";
    int n;
    std::cin >> n;

    return fact(n);
}

int main()
{
    std::cout << getFact() << std::endl;

    return 0;
}
