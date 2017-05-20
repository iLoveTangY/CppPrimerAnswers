#ifndef _EXE_22_
#define _EXE_22_
#pragma once

#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
	typedef std::vector<std::string > ::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//add and remove element
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	//visit element
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();
	//add const and the return type change to ConstStrBlobStr
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	//if data[i] is illegal, this function will throw out_of_range exception.
	void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	std::string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }


private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() : curr(0) { }
	//the parameter change to const StrBlob
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	//return type change to const string
	const std::string& deref() const;
	//the return type change to ConstStrBlobStr
	ConstStrBlobPtr& incr();
	bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }


private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};


#endif
