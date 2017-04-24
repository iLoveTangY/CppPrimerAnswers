#include "../include/Sales_item.h"
#include <iostream>

int main(void)
{
	Sales_item currItem, item;

	if(std::cin >> currItem)
	{
		int cnt = 1;
		while(std::cin >> item)
		{
			if(item.isbn() == currItem.isbn())
				++cnt;
			else
			{
				std::cout << currItem.isbn() << " occurs " << cnt << " times." << std::endl;
				currItem = item;
				cnt = 1;
			}
		}

		std::cout << currItem.isbn() << " occurs " << cnt << " times." << std::endl;
	}

	return 0;
}
