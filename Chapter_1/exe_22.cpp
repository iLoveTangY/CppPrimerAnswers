#include "../include/Sales_item.h"
#include <iostream>

int main(void)
{
	Sales_item sum, item;

	if(std::cin >> sum)
	{
	    while(std::cin >> item)
		    sum += item;

	    std::cout << sum << std::endl;
	}
	return 0;
}
