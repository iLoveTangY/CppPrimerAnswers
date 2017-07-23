#ifndef _BULK_QUOTE_
#define _BULK_QUOTE_
#pragma once

#include "exe_11_Quote.h"

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) { }
	double net_price(std::size_t n) const override
	{
		if (n >= min_qty)
			return n * (1 - discount) * price;
		else
			return n * price;
	}
	void debug() const override
	{
		Quote::debug();
		std::cout << min_qty << " " << discount << std::endl;
	}

private:
	std::size_t min_qty = 0;  //适用折扣的最低购买量
	double discount = 0.0;  //以小数表示的折扣额
};

#endif
