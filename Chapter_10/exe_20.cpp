#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	ifstream in(argv[0]);  //使用当前文件名
	if (!in)
	{
		cout << "Can't open file." << endl;
		exit(-1);
	}
	string word;
	vector<string> svec;
	while (in >> word)
		svec.push_back(word);

	auto cnt = count_if(svec.begin(), svec.end(),
		[](const string &s) { return s.size() > 6; });

	cout << "There are " << cnt << " words of length 6 or longer." << endl;

	return 0;
}