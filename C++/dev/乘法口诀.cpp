
#include <iostream>
using namespace std;

int main()
{
	system("cls"); // ����
	for (int i = 1; i <= 9; i++)
	{ // ����i��
		for (int j = 1; j <= i; j++)
		{ // ����j��
			int x;
			x = i * j;
			cout << j << "*" << i << "=" << x << " "; // ���iXj�Ľ��
		}
		cout << endl; // ÿ�д�ӡ�����
	}
	return 0;
}
