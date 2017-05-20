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

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
}

int main()
{
	destination d;
	f(d);

	return 0;
}