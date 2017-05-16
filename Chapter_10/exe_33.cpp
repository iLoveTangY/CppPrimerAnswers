#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;

void readFile(const string &infile, const string &outfile1, const string &outfile2)
{
	ifstream in(infile);
	if (!in)
	{
		cout << "Can't open file1 "  << endl;
		return;
	}
	ofstream odd_file(outfile1), even_file(outfile2);
	if (!odd_file)
	{
		cout << "Can't open file2 " << endl;
		return;
	}
	if (!even_file)
	{
		cout << "Can't open file2 " << endl;
		return;
	}
	istream_iterator<int> in_iter(in), eof;
	ostream_iterator<int> odd_iter(odd_file, " "), even_iter(even_file, "\n");

	while (in_iter != eof)
	{
		if (*in_iter & 1)
			*odd_iter++ = *in_iter;
		else
			*even_iter++ = *in_iter;
		++in_iter;
	}
}

int main(int argc, char **argv)
{
	readFile(argv[1], argv[2], argv[3]);

	return 0;
}