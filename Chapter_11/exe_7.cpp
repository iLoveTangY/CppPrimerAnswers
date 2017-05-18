#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void addFamily(map<string, vector<string>> &families, const string &family)
{
	if (families.find(family) == families.end())
		families[family] = vector<string> ();
}

void addChild(map<string, vector<string>> &families, const string &family, const string &child)
{
	families[family].push_back(child);
}

int main()
{
	map<string, vector<string>> families;

	addFamily(families, "James");
	addChild(families, "James", "Lebron");
	addChild(families, "James", "Jason");

	for (auto f : families)
	{
		cout << f.first << ": ";
		for (auto c : f.second)
			cout << c << " ";
		cout << endl;
	}

	return 0;
}