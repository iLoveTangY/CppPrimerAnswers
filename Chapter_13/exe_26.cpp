#include "exe_26.h"

using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { };

StrBlob::StrBlob(const StrBlob& s) : data(make_shared<vector<string>>(*s.data)) { }  //拷贝构造函数
StrBlob& StrBlob::operator=(const StrBlob& rhs)  //拷贝赋值运算符
{
	data = make_shared<vector<string>>(*rhs.data);
	return *this;
}

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