#ifndef _EXE_26_
#define _EXE_26_
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
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);

public:
	typedef std::vector<std::string > ::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);

	std::string& operator[](std::size_t n) { return (*data)[n]; }
	const std::string& operator[](std::size_t n) const { return (*data)[n]; }

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
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
	std::string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
	std::string& operator[](std::size_t n) { return (*wptr.lock())[n]; }
	const std::string& operator[](std::size_t n) const { return (*wptr.lock())[n]; }


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
