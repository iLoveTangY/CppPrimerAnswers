#include <regex>
#include <string>
#include <iostream>

using namespace std;
using namespace std::regex_constants;

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$2.$5.$7";
	while (getline(cin, s))
		cout << regex_replace(s, r, fmt) << endl;

	return 0;
}