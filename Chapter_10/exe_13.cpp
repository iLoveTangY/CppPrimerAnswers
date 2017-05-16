#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compareSize(const string &s)
{
	return s.size() <= 5;
}

int main()
{
	vector<string> svec = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };

	auto it = partition(svec.begin(), svec.end(), compareSize);
	while (it != svec.cend())
		cout << *it++ << " ";
	cout << endl;

	return 0;
}