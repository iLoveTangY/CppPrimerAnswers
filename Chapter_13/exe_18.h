#ifndef _EXE_18_
#define _EXE_18_
#pragma once

#include <string>

class Employee
{
public:
	Employee() { sn = seq++; }
	Employee(std::string _name) : name(_name) { sn = seq++; }

private :
	std::string name;
	int sn;
	static int seq;
};

#endif
