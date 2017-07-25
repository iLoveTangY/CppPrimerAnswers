#include <iostream>
#include <string>

using namespace std;

template<typename T, size_t N>
void print(const T(&arr)[N])
{
	for (auto iter = begin(arr); iter != end(arr); ++iter)
		cout << *iter << " ";
	cout << endl;
}

int main()
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	string s[5] = { "hello", "world", "red", "fox", "jump" };

	print(a);
	print(s);

	return 0;
}