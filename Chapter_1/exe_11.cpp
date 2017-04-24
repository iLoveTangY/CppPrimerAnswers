#include <iostream>

int main(void)
{
	int beg, end;

	std::cin >> beg;
	std::cin >> end;

	int val = beg;
	while(val <= end)
	{
		std::cout << val << std::endl;
		val++;
	}

	return 0;
}
