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

	double dvar = 3.1416;  //����Exercise::dvar
	int iobj = limit + 1; //ʹ��Exercise::limit
	++ivar;  //�����Է���
	++::ivar; //����ȫ�ֱ���ivar
}