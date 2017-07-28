#pragma once
#include "Sales_data"
#include <tuple>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::accumulate;
using std::equal_range;
using std::cout;
using std::endl;
using std::tuple;
using std::string;
using std::get;
using std::vector;

using matches = tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator>;

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), Sales_data(book),
			[](const Sales_data &sd1, const Sales_data &sd2)
			{ return sd1.isbn() < sd2.isbn(); });

		if (found.first != found.second)
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void reportResult(std::istream &in, std::ostream &os, const vector<vector<Sales_data>> &files)
{
	string s;
	while (std::cout << "Enter the book ISBN to look for: ", in >> s)
	{
		auto trans = findBook(files, s);
		if (trans.empty())
		{
			cout << s << " not found in any stores." << endl;
			continue;
		}
		for (auto&& store : trans)
		{
			os << "store " << get<0>(store) + 1 << " sales: "
				<< accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
		}

		cout << "-----" << endl;
	}
}