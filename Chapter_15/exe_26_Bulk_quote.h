#ifndef _EXE_26_BULK_QUOTE_
#define _EXE_26_BULK_QUOTE_
#pragma once

#include "exe_26_Quote.h"

class Bulk_quote : public Quote
{
public:
	Bulk_quote()
	{
		std::cout << "Bulk_quote Constructor" << std::endl;
	}

	Bulk_quote(const std::string &b, double p, size_t q, double d) :
		Quote(b, p), min_qty(q), discount(d)
	{
		std::cout << "Bulk_quote Copy Constructor" << std::endl;
	}

	Bulk_quote& operator=(const Bulk_quote &rhs)
	{
		std::cout << "Bulk_quote Copy assignment operator" << std::endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}

	Bulk_quote(Bulk_quote &&rhs) noexcept : Quote(rhs), min_qty(std::move(rhs.min_qty)),
		discount(std::move(rhs.discount))
	{
		std::cout << "Bulk_quote Move constructor" << std::endl;
	}

	Bulk_quote& operator=(Bulk_quote &&rhs) noexcept
	{
		std::cout << "Bulk_quote Move assignment operator" << std::endl;
		Quote::operator=(rhs);
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		return *this;
	}

	virtual ~Bulk_quote()
	{
		std::cout << "Bulk_quote destructor" << std::endl;
	}

	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty)
			return cnt * (1 - discount) *price;
		else
			return cnt * price;
	}

protected:
	size_t min_qty = 0;
	double discount = 0.0;
};

#endif
