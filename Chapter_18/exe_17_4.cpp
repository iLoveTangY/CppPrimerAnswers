namespace Exercise
{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

void manip()
{
	using namespace Exercise;

	double dvar = 3.1416;  //屏蔽Exercise::dvar
	int iobj = limit + 1; //使用Exercise::limit
	++ivar;  //二义性访问
	++::ivar; //访问全局变量ivar
}