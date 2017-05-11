#ifndef SALES_DATA
#define SALES_DATA

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isbn()
    {
        return bookNo;
    }
};

#endif // SALES_DATA
