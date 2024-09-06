#include <iostream>
#include <iomanip>
using namespace std;
int m;

int absA(int arr[20][20]) {
}

int main() {

	cout << "输入第一个矩阵阶数" << endl;
	cin >> m ;
	int arr[20][20];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];  //输入矩阵
	cout << "输入第一个矩阵" << endl;

	cout << "The result is:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2 * m; j++)
			cout << setw(3) << arr[i][j] ;    //打印矩阵
		cout << endl;
	}
	return 0;
}