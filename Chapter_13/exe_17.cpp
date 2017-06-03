#include <iostream>

using namespace std;

class Numbered
{
private:
	static int seq;
public:
	Numbered() { mysn = seq++; }
	Numbered(const Numbered& n) { mysn = seq++; }
	int mysn;
};

int Numbered::seq = 0;

void f(const Numbered &s)
{
	cout << s.mysn << endl;
}

int main()
{
	Numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}