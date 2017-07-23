#pragma once

#include "exe_15_Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &bookNo, double price, std::size_t qty, double disc) :
		Disc_quote(bookNo, price, qty, disc) { }
	double net_price(std::size_t cnt) const override
	{
		if (cnt > quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
};