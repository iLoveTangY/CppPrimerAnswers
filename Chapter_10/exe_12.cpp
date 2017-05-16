#include "../Chapter_7/exe_26.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compareIsbn(Sales_data &s1, Sales_data &s2)
{
	return s1.isbn().size() < s2.isbn().size();
}

int main()
{
	Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
	vector<Sales_data> v{ d1, d2, d3, d4, d5 };

	sort(v.begin(), v.end(), compareIsbn);
	for (auto elem : v)
		cout << elem.isbn() << " ";
	cout << endl;

	return 0;
}