#include "exe_35.h"
#include <iostream>

using namespace std;

void runQuries(ifstream &infile)
{
	TextQuery tq(infile);
	/*while (true)
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}*/
	//Query q = Query("fiery") & Query("bird") | Query("wind");
	//cout << q << endl;
}

int main()
{
	ifstream in;
	string fileName;
	cout << "Enter a file name: ";
	cin >> fileName;
	in.open(fileName);
	if (!in)
	{
		cout << "Can't open file." << endl;
		exit(-1);
	}
	runQuries(in);

	return 0;
}