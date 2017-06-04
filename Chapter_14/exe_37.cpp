#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class IntCompare
{
public:
	IntCompare(int v) : val(v) {}
	bool operator()(int v) { return val == v; }

private:
	int val;
};

int main()
{
	vector<int> vi = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	IntCompare ic(2);
	replace_if(vi.begin(), vi.end(), ic, 200);

	for (auto i : vi)
		cout << i << " ";
	cout << endl;

	return 0;
}