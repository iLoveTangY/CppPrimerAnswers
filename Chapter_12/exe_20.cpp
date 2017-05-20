#include "exe_19.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	StrBlob strBlob;
	ifstream in("input.txt");
	if (!in)
	{
		cout << "Can't open file." << endl;
		exit(-1);
	}
	string str;

	while (getline(in, str))
		strBlob.push_back(str);

	auto beg = strBlob.begin();
	while (beg != strBlob.end())
	{
		cout << beg.deref() << endl;
		beg.incr();
	}

	return 0;
}