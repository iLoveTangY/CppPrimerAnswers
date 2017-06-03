#include "exe_49_StrVec.h"
#include <algorithm>

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept :
elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec & StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec & StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();  //确保有空间容纳新元素
					//在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

void StrVec::resize(size_t n)
{
	if (n > size())
	{
		while (size() < n)
			push_back("");
	}
	else if (n < size())
	{
		while (size() > n)
			alloc.destroy(--first_free);
	}
}

void StrVec::resize(size_t n, const std::string & s)
{
	if (n > size())
	{
		while (size() < n)
			push_back(s);
	}
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);

	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	//不能传递给deallocate一个空指针
	if (elements)
	{
		//逆序销毁旧元素
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
		/* for_each(elements, first_free,
		[this](std::string &s) { alloc.destroy(&s); }); */
	}
}

void StrVec::reallocate(size_t newcapacity)
{
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
