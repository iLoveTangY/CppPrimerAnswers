#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<string> vec)
{
	for (auto elem : vec)
		cout << elem << " ";
	cout << endl;
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto endUnique = unique(words.begin(), words.end());
	printVector(words);
	words.erase(endUnique, words.end());
	printVector(words);
}

int main()
{
	vector<string> svec = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	printVector(svec);
	elimDups(svec);

	return 0;
}