#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

void printLst(list<int> lst)
{
	for (auto i : lst)
		cout << i << " ";
}

int main()
{
	vector<int> ivec;
	for (int i = 1; i < 10; ++i)
		ivec.push_back(i);
	
	list<int> inserterLst, back_inserterLst, front_inserterLst;

	copy(ivec.begin(), ivec.end(), inserter(inserterLst, inserterLst.begin()));
	copy(ivec.begin(), ivec.end(), back_inserter(back_inserterLst));
	copy(ivec.begin(), ivec.end(), front_inserter(front_inserterLst));

	cout << "ivec: ";
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;

	cout << "inserterLst: ";
	printLst(inserterLst);
	cout << endl;

	cout << "back_inserterLst: ";
	printLst(back_inserterLst);
	cout << endl;

	cout << "front_inserterLst: ";
	printLst(front_inserterLst);
	cout << endl;

	return 0;
}