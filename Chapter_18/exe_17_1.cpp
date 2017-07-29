namespace Exercise
{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

using Exercise::ivar;  //编译错误：ivar重复定义
using Exercise::dvar;
using Exercise::limit;

void manip()
{
	double dvar = 3.1416; //屏蔽了Exercise::dvar
	int iobj = limit + 1; //使用Exercise::limit
	++ivar;
	++::ivar;
}