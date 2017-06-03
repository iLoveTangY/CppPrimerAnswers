#include <iostream>
#include <vector>

using namespace std;

struct X
{
	X()
	{
		cout << "X()" << endl;
	}
	X(const X&) { cout << "X(const X&)" << endl; }
	X& operator=(const X&) { cout << "X:operator=" << endl; return *this; }
	~X() { cout << "~X()" << endl; }
};

void func(X x) {}
void func2(X& x) {}

int main()
{
	X x;
	func(x);
	func2(x);
	X x2;
	x2 = x;
	auto px = new X();
	vector<X> v;
	v.push_back(x);
	delete px;

	return 0;
}

/*
 此程序输出结果为：
 			X()   //创建x时调用构造函数
			X(const X&)  //将x作为形参赋给func的实参时调用拷贝构造函数
			~X()	//func执行结束后销毁形参x时调用析构函数
			X:operator=	 //x2=x调用拷贝赋值运算符
			X()		//new X()调用构造函数
			X(const X&)  //将x添加到容器中时调用拷贝构造函数
			~X()	//delete px时调用析构函数销毁动态分配的内存
			~X()	//销毁局部变量x
			~X()	//销毁容器中的X类型的元素
 */