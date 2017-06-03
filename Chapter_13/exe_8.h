#ifndef _EXE_8_H_
#define _EXE_8_H_
#pragma once

#include <string>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &hp)
	{
		ps = new std::string(*hp.ps);  //����psָ��Ķ��󣬶�����ָ�뱾��
		i = hp.i;
	}

	HasPtr& operator=(const HasPtr &hp)
	{
		auto newps = new std::string(*hp.ps);
		delete ps;
		ps = newps;
		i = hp.i;

		return *this;
	}

private:
	std::string *ps;
	int i;
};

#endif
