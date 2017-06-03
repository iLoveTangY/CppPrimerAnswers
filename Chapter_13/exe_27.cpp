#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) :
		ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr &p) :
		ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtr& operator=(const HasPtr& rhs);
	HasPtr& operator=(const string& rhs) { *ps = rhs; return *this; }
	string& operator*() { return *ps; }
	~HasPtr();

private:
	string *ps;
	int i;
	size_t *use;  //引用计数
};

HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use;
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

int main()
{
	HasPtr h("hi, mom");
	HasPtr h2 = h;
	h = "hi dad";

	cout << "h: " << *h << endl;
	cout << "h2: " << *h2 << endl;

	return 0;
}