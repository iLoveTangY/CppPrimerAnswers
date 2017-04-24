#include <iostream>

int main(void)
{
	//练习1.9
	int sum, val;
	for(sum = 0, val = 50; val <= 100; ++val)
		sum += val;

	std::cout << "Sum of 50 to 100 inclusive is "
		<< sum << std::endl;

	//练习1.10
	for(val = 10; val >= 0; --val)
		std::cout << val << std::endl;

	//练习1.11
	int beg, end;
	std::cin >> beg;
	std::cin >> end;
	for(val = beg; val <= end; ++val)
		std::cout << val << std::endl;

	return 0;
}
