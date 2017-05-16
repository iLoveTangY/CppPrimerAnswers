#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

void printList(list<string> lst)
{
	for (auto elem : lst)
		cout << elem << " ";
	cout << endl;
}

void elimDups(list<string> &words)
{
	words.sort();
	//sort(words.begin(), words.end());
	//auto endUnique = unique(words.begin(), words.end());
	printList(words);
	words.unique();
	//words.erase(endUnique, words.end());
	printList(words);
}

int main()
{
	list<string> svec = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	printList(svec);
	elimDups(svec);

	return 0;
}