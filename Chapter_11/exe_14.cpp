#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

void addFamily(map<string, vector<pair<string, string>>> &families, const string &family)
{
	if (families.find(family) == families.end())
		families[family];  //自动初始化一个空的vector
}

void addChild(map<string, vector<pair<string, string>>> &families, const string &family, 
	const string &child, const string &birthday)
{
	families[family].push_back({ child, birthday });
}

int main()
{
	map<string, vector<pair<string, string>>> families;

	addFamily(families, "James");
	addChild(families, "James", "Lebron", "1975-10-13");
	addChild(families, "James", "Jason", "1996-10-16");

	for (auto f : families)
	{
		cout << f.first << ": ";
		for (auto c : f.second)
			cout << c.first << " " << c.second << " ";
		cout << endl;
	}

	return 0;
}