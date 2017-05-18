#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<string> unique_word;
	string word;

	while (cin >> word)
	{
		if (find(unique_word.begin(), unique_word.end(), word) == unique_word.end())
			unique_word.push_back(word);
	}

	for (auto w : unique_word)
		cout << w << " ";
	cout << endl;

	return 0;
}