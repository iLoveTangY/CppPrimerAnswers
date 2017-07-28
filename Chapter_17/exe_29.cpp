#include <iostream>
#include <random>

using namespace std;

unsigned int rand_int(long seed = -1)
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 99999);

	if (seed >= 0)
		e.seed(seed);

	return u(e);
}

int main()
{
	for (int i = 0; i < 5; ++i)
		cout << rand_int() << " ";
	cout << endl;

	cout << rand_int(0) << endl;
	for (int i = 0; i < 5; ++i)
		cout << rand_int(i) << " ";
	cout << endl;

	return 0;
}