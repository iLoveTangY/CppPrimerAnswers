#include "exe_27.h"
#include <vector>
#include <numeric>
#include <memory>

using namespace std;

int main()
{
	vector<shared_ptr<Quote>> vecQuote;

	shared_ptr<Bulk_quote> spBulk0 = make_shared<Bulk_quote>("0-21-82470-1", 50, 5, 0.2);
	shared_ptr<Bulk_quote> spBulk1 = make_shared<Bulk_quote>("0-21-82470-1", 50, 3, 0.5);

	cout << "bulk_quote's total: " << spBulk0->net_price(5) + spBulk1->net_price(5) << endl;

	vecQuote.push_back(spBulk0);
	vecQuote.push_back(spBulk1);

	double total = std::accumulate(vecQuote.cbegin(), vecQuote.cend(), 0.0,
		[](double ret, shared_ptr<Quote> sp) {return ret += sp->net_price(5); });

	std::cout << "total in vector: " << total << endl;

	return 0;
}
