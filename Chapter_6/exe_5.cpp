#include <iostream>

int Abs(int n);

int main()
{
    int n;
    std::cin >> n;
    std::cout << Abs(n) << std::endl;

    return 0;
}

int Abs(int n)
{
    return (n > 0) ? n : -n;
}
