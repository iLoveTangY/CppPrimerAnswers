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
	using Exercise::dvar;  //�������dvar�ظ�����
	using Exercise::limit;

	double dvar = 3.1416;
	int iobj = limit + 1; //ʹ��Exercise::limit
	++ivar;  //����Exercise::ivar
	++::ivar; //����ȫ�ֱ���ivar
}