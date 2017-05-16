#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool checkSize(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

int main(int argc, char **argv)
{
	ifstream in(argv[0]);  //ʹ�õ�ǰ�ļ���
	if (!in)
	{
		cout << "Can't open file." << endl;
		exit(-1);
	}
	string word;
	vector<string> svec;
	while (in >> word)
		svec.push_back(word);

	auto cnt = count_if(svec.begin(), svec.end(), bind(checkSize, _1, 6));

	cout << "There are " << cnt << " words of length 6 or longer." << endl;

	return 0;
}