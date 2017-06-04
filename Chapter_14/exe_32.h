#pragma once

#include "exe_30_StrBlob.h"

class MyClass
{
public:
	std::string* operator->() const
	{
		return ptr->operator->();
	}

private:
	StrBlobPtr *ptr;
};
