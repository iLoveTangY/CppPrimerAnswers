#include <iostream>
#include <stdexcept>

int main(void)
{
    int x, y;

    std::cin >> x >> y;

    if(y == 0)
        throw std::runtime_error("�ڶ�����������0");

    std::cout << x / y << std::endl;

    return 0;
}
