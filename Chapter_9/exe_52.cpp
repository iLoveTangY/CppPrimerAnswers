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
void new_val(stack<obj> &so, double v)  //根据传入的数和栈进行一次计算并将结果压栈
{
	if (so.empty() || so.top().t == LP)  //栈空或为左括号
	{
		so.push(obj(VAL, v));  //将v构造为一个obj类型然后入栈
	}
	else if (so.top().t == ADD || so.top().t == SUB)  //之前为运算符
	{
		obj_type type = so.top().t;
		so.pop();  //将运算符弹出，此后栈顶为另一个运算数
		if (type == ADD)
			v += so.top().v;
		else
			v = so.top().v - v;
		so.pop();  //将另一个运算数弹出
		so.push(obj(VAL, v));  //运算结果压栈
	}
	else
		throw invalid_argument("缺少运算符");
}

int main()
{
	stack<obj> so;
	string exp;
	size_t p = 0, q;
	double v;

	cout << "请输入表达式：";
	getline(cin, exp);

	while (p < exp.size())
	{
		skipws(exp, p);  //跳过开头的空格
		if (exp[p] == '(')  //左括号直接入栈
		{
			so.push(obj(LP));
			++p;
		}
		else if (exp[p] == '+' || exp[p] == '-')
		{
			if (so.empty() || so.top().t != VAL)
				throw invalid_argument("缺少运算数");
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
				throw invalid_argument("未匹配右括号");
			if (so.top().t == LP)
				throw invalid_argument("空括号");
			if (so.top().t == VAL)  //此时的栈顶应该是括号内表达式的计算结果
			{
				v = so.top().v;
				so.pop();
				if (so.empty() || so.top().t != LP)  //此时栈顶必须得为左括号，因为括号内的表达式已经计算完毕
					throw invalid_argument("未匹配右括号");
				so.pop();  //将与右括号配对的左括号弹出
				new_val(so, v);
			}
			else
				throw invalid_argument("缺少运算数");
		}
		else  //运算数经过计算之后压栈
		{
			v = stod(exp.substr(p), &q); //将数字从string转为double
			p += q;
			new_val(so, v);
		}
	}

	if (so.size() != 1 || so.top().t != VAL)
		throw invalid_argument("非法表达式");

	cout << so.top().v << endl;
}
