#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7 };
	cout << "The sum is " << accumulate(ivec.cbegin(), ivec.cend(), 0)<< endl;

	return 0;
}