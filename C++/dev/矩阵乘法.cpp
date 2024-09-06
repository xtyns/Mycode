#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int m, s1, s2, n;
	cout << "输入第一个矩阵阶数" << endl;
	cin >> m >> s1;
	cout << "输入第二个矩阵阶数" << endl;
	cin >> s2 >> n;
	if (s1 != s2) {
		cout << "运算无法进行，矩阵不符合乘法规则！";
		return 0;
	}
	int arr1[m][s1];
	int arr2[s2][m];
	int times[m][n];
	cout << "输入第一个矩阵" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < s1; j++)
			cin >> arr1[i][j];  //输入arr1
	cout << "输入第二个矩阵阶数" << endl;
	for (int i = 0; i < s2; i++)
		for (int j = 0; j < n; j++)
			cin >> arr2[i][j];   //输入arr2
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			times[i][j] = 0;
			for (int k = 0; k < s1; k++)
				times[i][j] += arr1[i][k] * arr2[k][j];
		}   //矩阵乘法
	cout << "The result is:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(3) << times[i][j] ;    //打印矩阵
		cout << endl;
	}
	return 0;
}