#include <iostream>
#include <random>

using namespace std;

unsigned int rand_int()
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 99999);

	return u(e);
}

int main()
{
	for (int i = 0; i < 10; ++i)
		cout << rand_int() << " ";
	cout << endl;

	return 0;
}