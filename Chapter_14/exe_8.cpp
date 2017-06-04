#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream&, const Date&);

public:
	Date() {}
	Date(int y, int m, int d) : year(y), month(m), day(d) {}

private:
	int year, month, day;
};
ostream& operator<<(ostream &os, const Date &d)
{
	const char sep = '\t';
	os << "year:" << d.year << sep << "month:" << d.month << sep << "day:" << d.day << endl;

	return os;
}