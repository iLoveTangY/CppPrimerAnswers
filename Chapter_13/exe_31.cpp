#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);

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
	bool operator<(const HasPtr &rhs) const
	{
		return *ps < *rhs.ps;
	}
	~HasPtr()
	{
		delete ps;
	}

private:
	string *ps;
	int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	cout << "call swap()." << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

int main(int argc, char **argv)
{
	vector<HasPtr> vh;
	int n = atoi(argv[1]);
	for (int i = 0; i < n; i++)
		vh.push_back(to_string(n - i));

	for (auto p : vh)
		cout << *p << " ";
	cout << endl;

	sort(vh.begin(), vh.end());
	for (auto p : vh)
		cout << *p << " ";
	cout << endl;

	return 0;
}