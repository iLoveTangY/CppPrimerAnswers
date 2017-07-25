#include <iostream>
#include <string>

using namespace std;

template <typename T>
ostream& print(ostream &os, const T &t)
{
	return os << t << endl;
}

template <typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

int main()
{
	int i = 0;
	string s = "Hello";

	print(cout, i);
	print(cout, i, s);
	print(cout, i, s, 42.1, 'A', "End");

	return 0;
}