#include <iostream>

int main(void)
{
	int first, second;

	std::cin >> first;
	std::cin >> second;

	int beg, end;
	if(first > second)
	{
		beg = second;
		end = first;
	}
	else
	{
		beg = first;
		end = second;
	}

	int val = beg;
	while(val <= end)
	{
		std::cout << val << std::endl;
		val++;
	}

	return 0;
}
