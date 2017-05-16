#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> lst;

	copy(ivec.crbegin() + ivec.size() - 8, ivec.crbegin() + ivec.size() - 3, back_inserter(lst));

	for (auto i : lst)
		cout << i << " ";
	cout << endl;

	return 0;
}