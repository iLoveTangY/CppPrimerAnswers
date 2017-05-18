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

	//�汾1
	while (cin >> str >> num)
		pvec.push_back(make_pair(str, num));

	//�汾2
	while (cin >> str >> num)
		pvec.push_back({ str, num });

	//�汾3
	while (cin >> str >> num)
		pvec.push_back(pair<string, int>(str, num));

	for (auto p : pvec)
		cout << p.first << " " << p.second << endl;

	return 0;
}