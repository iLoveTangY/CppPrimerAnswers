#pragma once

#include "exe_15_Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
	using Disc_quote::Disc_quote;
	virtual double net_price(std::size_t cnt) const override
	{
		if (cnt >= quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
};