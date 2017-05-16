#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec = { 1, 2, 3, 4, 5 };
	fill_n(ivec.begin(), ivec.size(), 0);

	for (auto i : ivec)
		cout << i << " ";
	cout << endl;

	return 0;
}