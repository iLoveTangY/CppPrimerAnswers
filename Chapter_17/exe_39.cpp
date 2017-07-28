#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream inOut("copyOut", fstream::ate | fstream::in | fstream::out);
	if (!inOut)
	{
		cerr << "Unable to open file!" << endl;
		return EXIT_FAILURE;
	}

	auto end_mark = inOut.tellg();  //��סԭ�ļ�βλ��
	inOut.seekg(0, fstream::beg);  //�ض�λ���ļ���ʼ
	size_t cnt = 0;
	string line;

	while (inOut && inOut.tellg() != end_mark && getline(inOut, line))
	{
		cnt += line.size() + 1;
		auto mark = inOut.tellg();  //��ס��ȡλ��
		inOut.seekp(0, fstream::end); //��д����ƶ����ļ�β
		inOut << cnt;
		if (mark != end_mark)
			inOut << " ";
		inOut.seekg(mark); //�ָ���λ��
	}
	inOut.seekp(0, fstream::end);  //д��Ƕ�λ���ļ�β
	inOut << "\n";

	return 0;
}