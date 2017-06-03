#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}  //���캯��
	HasPtr(const HasPtr& hp)  //�������캯��
	{
		ps = new string(*hp.ps);
		i = hp.i;
	}
	HasPtr& operator=(const HasPtr& rhs)  //������ֵ�����
	{
		auto newps = new string(*rhs.ps);
		delete ps;  //����ԭstring
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
	h3 = "hi son";  //��Ϊ��ֵ��h��h2��h3ָ��ͬ��string

	cout << "h: " << *h << endl;
	cout << "h2: " << *h2 << endl;
	cout << "h3: " << *h3 << endl;

	return 0;
}