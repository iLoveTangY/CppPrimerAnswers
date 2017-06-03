#include "exe_49_String.h"
#include <vector>
#include <iostream>

void foo(String x)
{
	std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
	std::cout << x.c_str() << std::endl;
}

String baz()
{
	String ret("world");
	return ret;
}

int main()
{
	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(s0);  //copy constructor
	String s3 = s1;  //copy constructor
	String s4(text);
	s2 = s1;  //copy assignment

	foo(s1);  //copy constructor\n hello
	bar(s1);  //hello
	foo("temporary");  //temporary
	bar("temporary");  //temporary
	String s5 = baz(); //move constructor

	std::vector<String> svec;
	svec.reserve(8);
	svec.push_back(s0); //copy constructor
	svec.push_back(s1); //copy constructor
	svec.push_back(s2); //copy constructor
	svec.push_back(s3); //copy constructor
	svec.push_back(s4); //copy constructor
	svec.push_back(s5); //copy constructor
	svec.push_back(baz()); //move constructor move constructor
	svec.push_back("good job"); //move constructor

	for (const auto& s : svec) {
		std::cout << s.c_str() << std::endl;
	}
}