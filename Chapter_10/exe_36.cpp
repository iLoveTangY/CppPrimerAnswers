#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> lst = { 2, 1, 9, 0, 2, 0 };
	int p = 0;

	auto first_zero = find(lst.cbegin(), lst.cend(), 0);

	if (first_zero == lst.cend())
		cout << "There are no zero in container." << endl;
	else
	{
		auto last_zero = find(lst.crbegin(), lst.crend(), 0);

		for (auto iter = lst.begin(); iter != last_zero.base(); ++iter, ++p)
			;
		cout << "The last zero in the index of " << --p << endl;
	}

	return 0;
}