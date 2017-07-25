#include <iostream>
#include <sstream>

using namespace std;

template <typename T> string debug_rep(const T &t);
template <typename T> string debug_rep(T *p);

string debug_rep(const string &s);
string debug_rep(char *p);
string debug_rep(const char *p);

template<typename T> string debug_rep(const T &t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}

template<typename T> string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer: " << p;

	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";

	return ret.str();
}

string debug_rep(const string &s)
{
	return '"' + s + '"';
}

//将字符指针转为string，并且调用string版本的debug_rep函数
string debug_rep(char *p)
{
	return debug_rep(string(p));
}

string debug_rep(const char *p)
{
	return debug_rep(string(p));
}

int main()
{

}