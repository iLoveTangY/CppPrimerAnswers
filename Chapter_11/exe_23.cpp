#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void addChild(multimap<string, string> &families, const string &family, const string &child)
{
	families.insert({ family, child });
}

int main()
{
	multimap<string, string> families;

	addChild(families, "James", "Lebron");
	addChild(families, "James", "Jason");

	for (auto f : families)
	{
		cout << f.first << ": " << f.second << endl;
	}

	return 0;
}