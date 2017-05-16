#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	list<string> slst = { "This", "is", "a", "test", "list", "string", "list" };
	string str = "list";

	cout << "The value " << str << " occurs "
		<< count(slst.cbegin(), slst.cend(), str) << " times." << endl;

	return 0;
}