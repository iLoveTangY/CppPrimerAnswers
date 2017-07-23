#ifndef _EXE_26_
#define _EXE_26
#pragma once

#include <iostream>
#include <string>

class Quote
{
public:
	Quote()
	{
		std::cout << "Quote Constructor" << std::endl;
	}

	Quote(const std::string &b, double p) : bookNo(b), price(p)
	{
		std::cout << "Quote Constructor taking two parameters" << std::endl;
	}

	Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price)
	{
		std::cout << "Quote Copy Constructor" << std::endl;
	}

	Quote& operator=(const Quote &rhs)
	{
		std::cout << "Quote Copy assignment operator" << std::endl;
		price = rhs.price;
		bookNo = rhs.bookNo;
		return *this;
	}

	Quote(Quote &&rhs) noexcept : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price))
	{
		std::cout << "Quote Move Constructor" << std::endl;
	}

	Quote& operator=(Quote &&rhs) noexcept
	{
		std::cout << "Quote Move assignment operator" << std::endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}

	virtual ~Quote()
	{
		std::cout << "Quote Destructor" << std::endl;
	}

	std::string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }

private:
	std::string bookNo;
	
protected:
	double price = 0.0;
};

#endif
