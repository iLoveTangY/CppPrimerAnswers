#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto endUnique = unique(words.begin(), words.end());
	words.erase(endUnique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	/*stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b)
	{ return a.size() < b.size(); });*/

	auto wc = partition(words.begin(), words.end(),
		[sz](const string &a)
	{return a.size() < sz; });

	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer." << endl;
	/*for_each(wc, words.end(),
	[](const string &s) { cout << s << " "; });*/
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