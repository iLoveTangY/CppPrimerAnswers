#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	ifstream in("E:\\C++Primer5th\\Chapter_10\\Text.txt");
	if (!in)
	{
		cout << "Can't open file." << endl;
		exit(-1);
	}
	vector<string> svec;
	istream_iterator<string> infile_iter(in), eof;

	while (infile_iter != eof)
		svec.push_back(*infile_iter++);

	for (auto str : svec)
		cout << str << " ";
	cout << endl;

	return 0;
}