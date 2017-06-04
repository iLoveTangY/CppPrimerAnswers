#include "exe_16_StrBlob.h"
#include <iostream>

using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { };

void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}


const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());

	return ret;
}

ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
	auto ret = ConstStrBlobPtr(*this, data->size());

	return ret;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;

	return *this;
}

const std::string & ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");

	return (*p)[curr];
}

ConstStrBlobPtr & ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobStr");
	++curr;

	return *this;
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}


int main()
{
	const StrBlob b = { "hello", "world", "!" };

	for (auto it = b.begin(); it != b.end(); it.incr())
		cout << it.deref() << endl;

	return 0;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}
