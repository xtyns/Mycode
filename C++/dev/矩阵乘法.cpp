#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int m, s1, s2, n;
	cout << "�����һ���������" << endl;
	cin >> m >> s1;
	cout << "����ڶ����������" << endl;
	cin >> s2 >> n;
	if (s1 != s2) {
		cout << "�����޷����У����󲻷��ϳ˷�����";
		return 0;
	}
	int arr1[m][s1];
	int arr2[s2][m];
	int times[m][n];
	cout << "�����һ������" << endl;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < s1; j++)
			cin >> arr1[i][j];  //����arr1
	cout << "����ڶ����������" << endl;
	for (int i = 0; i < s2; i++)
		for (int j = 0; j < n; j++)
			cin >> arr2[i][j];   //����arr2
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			times[i][j] = 0;
			for (int k = 0; k < s1; k++)
				times[i][j] += arr1[i][k] * arr2[k][j];
		}   //����˷�
	cout << "The result is:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(3) << times[i][j] ;    //��ӡ����
		cout << endl;
	}
	return 0;
}