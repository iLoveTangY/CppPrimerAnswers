#include <iostream>

int main(void)
{
	int sum = 0, val = 0;

	while(std::cin >> val)
		sum += val;

	std::cout << "Sum is " << sum << std::endl;

	return 0;
}
