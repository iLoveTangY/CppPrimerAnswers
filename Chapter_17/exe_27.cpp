#include <regex>
#include <string>
#include <iostream>

using namespace std;
using namespace std::regex_constants;

int main()
{
	string zip = "(\\d{5})((-?)(\\d{4}))?";
	regex r(zip);
	string s;
	string fmt = "$1-$2";
	while (getline(cin, s))
		cout << regex_replace(s, r, fmt) << endl;

	return 0;
}