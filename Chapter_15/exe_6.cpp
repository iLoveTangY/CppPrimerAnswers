#include "exe_5_Bulk_quote.h"

using namespace std;

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << "total due: " << ret << endl;

	return ret;
}

int main()
{
	Quote q("IQUOTE-32232-2NJED", 32.2);
	Bulk_quote b("IBULK-32323-2JDIE", 32.3, 3, 0.5);

	print_total(cout, q, 5);
	print_total(cout, b, 4);

	return 0;
}