#ifndef _EXE_19_
#define _EXE_19_
#pragma once

#include <string>

class Employee
{
public:
	Employee() { sn = seq++; }
	Employee(std::string _name) : name(_name) { sn = seq++; }
	Employee(const Employee& e)  //�Լ�����Ŀ������캯��
	{
		name = e.name;
		sn = seq++;
	}
	Employee& operator=(const Employee& e)  //�Զ��忽����ֵ����
	{
		name = e.name;
		sn = seq++;
	}
	std::string name;
	int sn;

private:
	static int seq;
};

#endif
