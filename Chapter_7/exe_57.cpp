#include "exe_57.h"

void Account::rate(double newRate)
{
    interestRate = newRate;
}

//��̬���ݳ�Ա�Ķ���Ӧ�������������������Ķ������һ���ļ�����
double Account::interestRate = initRate();
