#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

int main()
{
	auto data = { 2, 3, 4, 5 };
	int input;
	std::cin >> input;
	std::modulus<int> mod;
	auto predicator = [&](int i) { return 0 != mod(input, i); };
	auto is_divisible = (std::count_if(data.begin(), data.end(), predicator) == 0);
	std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;

	return 0;
}