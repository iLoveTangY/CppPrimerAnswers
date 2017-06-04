#ifndef _EXE_26_
#define _EXE_26_
#pragma once

#include <string>
#include <memory>
#include <utility>

class StrVec
{
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
	friend bool operator<(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>=(const StrVec &lhs, const StrVec &rhs);

public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(std::initializer_list<std::string> il)
	{
		auto newdata = alloc_n_copy(il.begin(), il.end());
		elements = newdata.first;
		first_free = cap = newdata.second;
	}
	StrVec(const StrVec&);
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec&&) noexcept;
	~StrVec();

	std::string& operator[](std::size_t n) { return elements[n]; }
	const std::string& operator[](std::size_t n) const { return elements[n]; }

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	void reserve(size_t n) { if (n > capacity()) reallocate(n); }
	void resize(size_t n);
	void resize(size_t n, const std::string &s);


private:
	std::allocator<std::string> alloc;
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	std::pair<std::string*, std::string*> alloc_n_copy
	(const std::string *, const std::string *);
	void free();
	void reallocate(size_t newcapacity);
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

#endif
