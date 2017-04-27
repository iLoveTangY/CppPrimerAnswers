#include <iostream>

int main(void)
{
    int a[10];

    int *ptr = a;

    while(ptr < a+10)
    {
        *ptr = 0;
        ++ptr;
    }

    for(auto i : a)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
