#include <cstring>
#include <iostream>

int main(void)
{
    const char ca[] = "hello", cb[] = "world";
    char cc[12];

    strcpy(cc, ca);
    strcat(cc, " ");
    strcat(cc, cb);

    std::cout << cc << std::endl;

    return 0;
}
