#include "exe_35.h"
#include <vector>

using namespace std;

int main()
{
	ReadString rs;
	vector<string> vs;

	while (true)
	{
		string line = rs();
		if (!line.empty())
			vs.push_back(line);
		else
			break;
	}

	return 0;
}