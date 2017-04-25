#include <iostream>

int main(void)
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;

    auto &g = ci;

    a = 42;
    b = 42;
    c = 42;
    //d = 42;  //false d是个指向int类型的指针
    //e = 42;  //false e是个指向int类型常量的指针
    // g = 42;  //false g是个整形常量引用

    return 0;
}
