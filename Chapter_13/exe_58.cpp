#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo
{
public:
	Foo sorted() && ;  //可用于可改变的右值
	Foo sorted() const &;  //任何类型的Foo都可

private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	cout << "左值引用" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	cout << "右值引用" << endl;
	Foo ret(*this);
	return ret.sorted();
	//return Foo(*this).sorted();
}

int main()
{
	Foo f;
	f.sorted();

	return 0;
}