#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec = { 1, 2, 3, 4, 5 };

	for (auto iter = ivec.cend(); iter != ivec.cbegin(); )
		cout << *(--iter) << " ";
	cout << endl;

	return 0;
}