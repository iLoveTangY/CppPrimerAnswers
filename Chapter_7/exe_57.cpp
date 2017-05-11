#include "exe_57.h"

void Account::rate(double newRate)
{
    interestRate = newRate;
}

//静态数据成员的定义应该与其他非内联函数的定义放在一个文件夹中
double Account::interestRate = initRate();
