#include "exe_7.h"
#include <algorithm>
#include <iostream>

String::String(const char *s)
{
	char *s1 = const_cast<char *>(s);
	while (*s1)
		++s1;
	range_initializer(s, ++s1);
}

String::String(const String &s)
{
	range_initializer(s.elements, s.end);
	std::cout << "copy constructor" << std::endl;
}

String::String(String &&s) noexcept : elements(s.elements), end(s.end)
{
	s.elements = s.end = nullptr;
	std::cout << "move constructor" << std::endl;
}


String & String::operator=(const String &rhs)
{
	auto newstr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newstr.first;
	end = newstr.second;
	std::cout << "copy-assignment" << std::endl;

	return *this;
}

String & String::operator=(String &&rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
		std::cout << "move assignment" << std::endl;
	}
	return *this;
}

String::~String()
{
	free();
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto str = alloc.allocate(e - b);
	return { str, std::uninitialized_copy(b, e, str) };
}

void String::range_initializer(const char *first, const char *last)
{
	auto newstr = alloc_n_copy(first, last);
	elements = newstr.first;
	end = newstr.second;
}

void String::free()
{
	if (elements)
	{
		std::for_each(elements, end, [this](char& c) { alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}
}

std::ostream& operator<<(std::ostream &os, const String &s)
{
	os << s;
	return os;
}
