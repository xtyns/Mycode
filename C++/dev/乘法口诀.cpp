
#include <iostream>
using namespace std;

int main()
{
	system("cls"); // 清屏
	for (int i = 1; i <= 9; i++)
	{ // 共有i列
		for (int j = 1; j <= i; j++)
		{ // 共有j行
			int x;
			x = i * j;
			cout << j << "*" << i << "=" << x << " "; // 输出iXj的结果
		}
		cout << endl; // 每行打印完后换行
	}
	return 0;
}
