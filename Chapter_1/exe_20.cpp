#include "../include/Sales_item.h"
#include <iostream>

int main(void)
{
	Sales_item item;

	while(std::cin >> item)
		std::cout << item << std::endl;

	return 0;
}
