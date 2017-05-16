#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ivec = { 1, 2, 3, 4, 5, 6 };

	for (auto rbeg = ivec.crbegin(); rbeg != ivec.crend(); ++rbeg)
		cout << *rbeg << " ";
	cout << endl;

	return 0;
}