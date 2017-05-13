#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <stdexcept>

using namespace std;

enum obj_type { LP, RP, ADD, SUB, VAL };
struct obj
{
	obj(obj_type type, double val = 0)
	{
		t = type;
		v = val;
	}

	obj_type t;
	double v;
};

inline
void skipws(string &exp, size_t &p)
{
	p = exp.find_first_not_of(" ", p);
}

inline
void new_val(stack<obj> &so, double v)  //���ݴ��������ջ����һ�μ��㲢�����ѹջ
{
	if (so.empty() || so.top().t == LP)  //ջ�ջ�Ϊ������
	{
		so.push(obj(VAL, v));  //��v����Ϊһ��obj����Ȼ����ջ
	}
	else if (so.top().t == ADD || so.top().t == SUB)  //֮ǰΪ�����
	{
		obj_type type = so.top().t;
		so.pop();  //��������������˺�ջ��Ϊ��һ��������
		if (type == ADD)
			v += so.top().v;
		else
			v = so.top().v - v;
		so.pop();  //����һ������������
		so.push(obj(VAL, v));  //������ѹջ
	}
	else
		throw invalid_argument("ȱ�������");
}

int main()
{
	stack<obj> so;
	string exp;
	size_t p = 0, q;
	double v;

	cout << "��������ʽ��";
	getline(cin, exp);

	while (p < exp.size())
	{
		skipws(exp, p);  //������ͷ�Ŀո�
		if (exp[p] == '(')  //������ֱ����ջ
		{
			so.push(obj(LP));
			++p;
		}
		else if (exp[p] == '+' || exp[p] == '-')
		{
			if (so.empty() || so.top().t != VAL)
				throw invalid_argument("ȱ��������");
			if (exp[p] == '+')
				so.push(obj(ADD));
			else
				so.push(obj(SUB));
			++p;
		}
		else if (exp[p] == ')')
		{
			++p;
			if (so.empty())
				throw invalid_argument("δƥ��������");
			if (so.top().t == LP)
				throw invalid_argument("������");
			if (so.top().t == VAL)  //��ʱ��ջ��Ӧ���������ڱ��ʽ�ļ�����
			{
				v = so.top().v;
				so.pop();
				if (so.empty() || so.top().t != LP)  //��ʱջ�������Ϊ�����ţ���Ϊ�����ڵı��ʽ�Ѿ��������
					throw invalid_argument("δƥ��������");
				so.pop();  //������������Ե������ŵ���
				new_val(so, v);
			}
			else
				throw invalid_argument("ȱ��������");
		}
		else  //��������������֮��ѹջ
		{
			v = stod(exp.substr(p), &q); //�����ִ�stringתΪdouble
			p += q;
			new_val(so, v);
		}
	}

	if (so.size() != 1 || so.top().t != VAL)
		throw invalid_argument("�Ƿ����ʽ");

	cout << so.top().v << endl;
}
