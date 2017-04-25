#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(void)
{
    Sales_data item, total;
    double price = 0;

    if(std::cin >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        while(std::cin >> item.bookNo >> item.units_sold >> price)
        {
            item.revenue = item.units_sold * price;
            total.units_sold += item.units_sold;
            total.revenue += item.revenue;
        }
        std::cout << total.bookNo << " " << total.units_sold
                << " " << total.revenue << std::endl;
    }

    return 0;
}
