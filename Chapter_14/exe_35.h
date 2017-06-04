#ifndef _EXE_35_
#define _EXE_35_

#include <iostream>
#include <string>

class ReadString
{
public:
	ReadString(std::istream &_is = std::cin) : is(_is) {}
	std::string operator()()
	{
		std::string line;
		if (!getline(is, line))
			line = " ";
		return line;
	}

private:
	std::istream &is;
};

#endif