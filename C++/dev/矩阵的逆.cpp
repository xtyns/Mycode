#include <iostream>
#include <iomanip>
using namespace std;
int m;

int absA(int arr[20][20]) {
}

int main() {

	cout << "�����һ���������" << endl;
	cin >> m ;
	int arr[20][20];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];  //�������
	cout << "�����һ������" << endl;

	cout << "The result is:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2 * m; j++)
			cout << setw(3) << arr[i][j] ;    //��ӡ����
		cout << endl;
	}
	return 0;
}