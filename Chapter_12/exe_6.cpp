#include <iostream>
#include <vector>

using namespace std;

vector<int> * new_vector(void)
{
	return new(nothrow) vector<int>();
}

void read_ints(vector<int> *pv)
{
	int v;

	while (cin >> v)
		pv->push_back(v);
}

void print_ints(vector<int> *pv)
{
	for (auto i : *pv)
		cout << i << " ";
	cout << endl;
}

int main(void)
{
	vector<int> *pv = new_vector();
	if (!pv)
	{
		cout << "Out of memory." << endl;
		exit(-1);
	}
	read_ints(pv);
	print_ints(pv);
	delete pv;

	return 0;
}