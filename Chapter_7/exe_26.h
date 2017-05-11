#ifndef EXE_26
#define EXE_26

#include <string>

class Sales_data
{
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

    //构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p * n) { }
    Sales_data(std::istream &);

private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

 //本题要求
inline
double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

#endif // EXE_26




