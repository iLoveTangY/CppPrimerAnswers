namespace Exercise
{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

void manip()
{
	using Exercise::ivar;
	using Exercise::dvar;  //编译错误：dvar重复定义
	using Exercise::limit;

	double dvar = 3.1416;
	int iobj = limit + 1; //使用Exercise::limit
	++ivar;  //访问Exercise::ivar
	++::ivar; //访问全局变量ivar
}