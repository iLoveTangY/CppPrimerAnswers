#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);
	friend bool operator==(const Date&, const Date&);
	friend bool operator!=(const Date&, const Date&);
	friend bool operator<(const Date &lhs, const Date &rhs);
	friend bool operator<=(const Date &lhs, const Date &rhs);
	friend bool operator>(const Date &lhs, const Date &rhs);
	friend bool operator>=(const Date &lhs, const Date &rhs);

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

istream& operator>>(istream &is, Date &d)
{
	is >> d.year >> d.month >> d.day;
	if (!is)
		d = Date(0, 0, 0);
	return is;
}

bool operator==(const Date &lhs, const Date &rhs)
{
	return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}
bool operator!=(const Date &lhs, const Date &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Date &lhs, const Date &rhs)
{
	return (lhs.year < rhs.year) || (lhs.year == rhs.year && lhs.month < rhs.month)
		|| (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day);
}
bool operator<=(const Date &lhs, const Date &rhs)
{
	return (lhs < rhs) || (lhs == rhs);
}
bool operator>(const Date &lhs, const Date &rhs)
{
	return !(lhs <= rhs);
}
bool operator>=(const Date &lhs, const Date &rhs)
{
	return (lhs > rhs) || (lhs == rhs);
}