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
    //d = 42;  //false d�Ǹ�ָ��int���͵�ָ��
    //e = 42;  //false e�Ǹ�ָ��int���ͳ�����ָ��
    // g = 42;  //false g�Ǹ����γ�������

    return 0;
}
