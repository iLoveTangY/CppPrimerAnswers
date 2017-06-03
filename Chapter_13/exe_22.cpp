#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}  //构造函数
	HasPtr(const HasPtr& hp)  //拷贝构造函数
	{
		ps = new string(*hp.ps);
		i = hp.i;
	}
	HasPtr& operator=(const HasPtr& rhs)  //拷贝赋值运算符
	{
		auto newps = new string(*rhs.ps);
		delete ps;  //销毁原string
		ps = newps;
		i = rhs.i;

		return *this;
	}
	HasPtr& operator=(const string& rhs)
	{
		*ps = rhs;
		return *this;
	}
	string& operator*()
	{
		return *ps;
	}
	~HasPtr()
	{
		delete ps;
	}

private:
	string *ps;
	int i;
};

int main()
{
	HasPtr h("hi mom");
	HasPtr h2(h);
	HasPtr h3 = h;
	h2 = "hi dad";
	h3 = "hi son";  //行为类值，h、h2、h3指向不同的string

	cout << "h: " << *h << endl;
	cout << "h2: " << *h2 << endl;
	cout << "h3: " << *h3 << endl;

	return 0;
}