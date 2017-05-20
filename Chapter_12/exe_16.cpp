#include <memory>

using namespace std;

int main()
{
	unique_ptr<int> u1(new int(42));
	unique_ptr<int> u2 = u1;  //error

	return 0;
}