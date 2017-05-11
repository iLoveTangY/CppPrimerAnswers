#ifndef EXE_41
#define EXE_41

#include <string>
#include <iostream>

class Sales_data
{
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p * n) { std::cout << "3 parameter construct function" << std::endl; }
    //¹¹Ôìº¯Êý
    Sales_data() : Sales_data("", 0, 0) { std::cout << "empty parameter construct function" << std::endl; }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) { std::cout << "string object as parameter" << std::endl; }

    Sales_data(std::istream &is) : Sales_data()
    {
        std::cout << "istream object as parameter" << std::endl;
        read(is, *this);
    }

private:
    inline double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

inline
double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

#endif // EXE_41





