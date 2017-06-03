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
 �˳���������Ϊ��
 			X()   //����xʱ���ù��캯��
			X(const X&)  //��x��Ϊ�βθ���func��ʵ��ʱ���ÿ������캯��
			~X()	//funcִ�н����������β�xʱ������������
			X:operator=	 //x2=x���ÿ�����ֵ�����
			X()		//new X()���ù��캯��
			X(const X&)  //��x��ӵ�������ʱ���ÿ������캯��
			~X()	//delete pxʱ���������������ٶ�̬������ڴ�
			~X()	//���پֲ�����x
			~X()	//���������е�X���͵�Ԫ��
 */