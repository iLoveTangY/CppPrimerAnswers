#include "exe_27.h"
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<Quote> vecQuote;

	Bulk_quote bulk0("0-21-82470-1", 50, 5, 0.2);
	Bulk_quote bulk1("0-21-82470-1", 50, 3, 0.5);

	cout << "bulk_quote's total: " << bulk0.net_price(5) + bulk1.net_price(5) << endl;

	vecQuote.push_back(bulk0);
	vecQuote.push_back(bulk1);

	double total = std::accumulate(vecQuote.cbegin(), vecQuote.cend(), 0.0,
		[](double ret, const Quote &obj) {return ret += obj.net_price(5); });

	std::cout << "total in vector: " << total << endl;

	return 0;
}
