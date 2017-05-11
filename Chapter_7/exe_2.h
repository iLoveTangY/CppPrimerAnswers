#ifndef EXE_2
#define EXE_2

#include <string>

struct Sales_data
{
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif // EXE_2
