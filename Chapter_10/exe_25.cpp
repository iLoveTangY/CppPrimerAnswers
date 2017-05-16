#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words)  //Ïû³ýÖØ¸´µ¥´Ê
{
	sort(words.begin(), words.end());
	auto endUnique = unique(words.begin(), words.end());
	words.erase(endUnique, words.end());
}

bool checkSize(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);

	auto wc = partition(words.begin(), words.end(), bind(checkSize, _1, sz));

	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer." << endl;

	while (wc != words.end())
		cout << *wc++ << " ";
	cout << endl;
}

int main()
{
	vector<string> svec = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(svec, 4);

	return 0;
}