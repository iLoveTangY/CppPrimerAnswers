#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

string &trans(string &s)
{
	set<char> punc = { ',', '.', ';', '!', '(', ')' };
	for (int index = 0; index < s.size(); ++index)
	{
		if (s[index] >= 'A' && s[index] <= 'Z')
			s[index] -= ('A' - 'a');
		else if (punc.find(s[index]) != punc.end())
			s.erase(index, 1);
	}

	return s;
}

int main()
{
	map<string, size_t> word_count;
	set<string> exclude = { "the", "but", "and", "or", "an", "a" };
	string word;
	while (cin >> word)
	{
		word = trans(word);
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	}
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;

	return 0;
}