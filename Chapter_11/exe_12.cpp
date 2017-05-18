#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	string str;
	int num;
	vector<pair<string, int>> pvec;

	while (cin >> str >> num)
		pvec.push_back(make_pair(str, num));

	for (auto p : pvec)
		cout << p.first << " " << p.second << endl;

	return 0;
}