#pragma once

#include <memory>
#include <set>
#include "exe_30_Quote_Bulk.h"

using std::shared_ptr;

class Basket
{
public:
	Basket() = default;
	void add_item(const Quote &sale) { items.insert(shared_ptr<Quote>(sale.clone())); }
	void add_item(Quote &&sale) { items.insert(shared_ptr<Quote>(std::move(sale).clone())); }
	inline double total_receipt(std::ostream&) const;

private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

inline double Basket::total_receipt(std::ostream &os) const
{
	auto sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}