#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	vector<int> ivec = { 1, 1, 5, 3, 5, 9, 3, 3, 7, 5, 6 };
	list<int> ilst;

	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));

	for (auto i : ilst)
		cout << i << " ";
	cout << endl;

	return 0;
}