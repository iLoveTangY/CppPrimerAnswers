#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool checkSize(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

int main()
{
	vector<int> ivec = { 1, 3, 5, 7, 9, 13, 17, 23 };
	string str = "test";

	auto p = find_if(ivec.begin(), ivec.end(), bind(checkSize, str, _1));

	cout << "The first is " << *p << endl;

	return 0;
}