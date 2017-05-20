#include <iostream>
#include <memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
	cout << "Open the connection" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "Close the connection." << endl;
}

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
}

int main()
{
	destination d;
	f(d);

	return 0;
}