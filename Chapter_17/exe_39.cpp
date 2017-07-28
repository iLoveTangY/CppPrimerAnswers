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

	auto end_mark = inOut.tellg();  //记住原文件尾位置
	inOut.seekg(0, fstream::beg);  //重定位到文件开始
	size_t cnt = 0;
	string line;

	while (inOut && inOut.tellg() != end_mark && getline(inOut, line))
	{
		cnt += line.size() + 1;
		auto mark = inOut.tellg();  //记住读取位置
		inOut.seekp(0, fstream::end); //将写标记移动到文件尾
		inOut << cnt;
		if (mark != end_mark)
			inOut << " ";
		inOut.seekg(mark); //恢复读位置
	}
	inOut.seekp(0, fstream::end);  //写标记定位到文件尾
	inOut << "\n";

	return 0;
}