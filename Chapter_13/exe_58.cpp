#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo
{
public:
	Foo sorted() && ;  //�����ڿɸı����ֵ
	Foo sorted() const &;  //�κ����͵�Foo����

private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	cout << "��ֵ����" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	cout << "��ֵ����" << endl;
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