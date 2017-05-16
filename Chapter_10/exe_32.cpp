#include "../include/Sales_item.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<Sales_item> vs;
	istream_iterator<Sales_item> in_iter(cin), eof;

	while (in_iter != eof)
		vs.push_back(*in_iter++);

	if (vs.empty())
	{
		cerr << "No data?!" << endl;
		return -1;
	}

	sort(vs.begin(), vs.end(), compareIsbn);

	auto l = vs.begin();
	while (l != vs.end())
	{
		auto item = *l;  //��ͬISBN���׼�¼�еĵ�һ��
		//�ں�����¼�в������һ��ISBN��item��ͬ��
		auto r = find_if(l + 1, vs.end(),
			[item](const Sales_item &item1)
		{ return item1.isbn() != item.isbn(); });
		//��[l, r)��Ľ��׼�¼�ۼӲ����
		cout << accumulate(l + 1, r, item) << endl;
		//ָ����һ��
		l = r;
	}

	return 0;
}