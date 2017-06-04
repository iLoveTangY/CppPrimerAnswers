#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class StrLen
{
public:
	StrLen(int min, int max) : minLen(min), maxLen(max) { }
	bool operator()(const string &str) { return str.length() >= minLen && str.length() <= maxLen; }

private:
	int minLen, maxLen;
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
	const int maxLen = 9;
	StrLen sl(minLen, maxLen);
	int l = vec.size();
	int s = count_if(vec.begin(), vec.end(), sl);
	cout << "len 1~9: " << s << endl;
	cout << "len>=10: " << l - s << endl;

	return 0;
}