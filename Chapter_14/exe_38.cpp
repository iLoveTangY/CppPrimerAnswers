#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class StrLen
{
public:
	StrLen(int l) : len(l) { }
	bool operator()(const string &str) { return str.length() == len; }

private:
	int len;
};

void readStr(istream &is, vector<string> &vec)
{
	string word;
	while (is >> word)
		vec.push_back(word);
}

int main()
{
	vector<string> vec;
	readStr(cin, vec);
	const int minLen = 1;
	const int maxLen = 10;
	for (int i = minLen; i <= maxLen; ++i)
	{
		StrLen sl(i);
		cout << "len: " << i << ", cnt: " << count_if(vec.begin(), vec.end(), sl) << endl;
	}

	return 0;
}