#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename I, typename T>
I My_find(I b, I e, const T &v)
{
	while (b != e && *b != v)
		b++;
	return b;
}

int main()
{
	vector<int> iv = {1, 2, 3, 4, 5};
	auto iter = My_find(iv.begin(), iv.end(), 4);
	if (iter == iv.end())
		cout << "Can't find 4!" << endl;
	else
		cout << "Find 4 in position " << iter - iv.begin() << endl;

	list<string> ls = { "hello", "world", "fuck" };
	auto iter1 = My_find(ls.begin(), ls.end(), "hello");
	if (iter1 == ls.end())
		cout << "Can't find hello!" << endl;
	else
		cout << "Found hello." << endl;

	return 0;
}