#include <iostream>
#include <string>
using namespace std;

//�ɼ�����
struct student {
	string name;
	int score;
} stu[20];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> stu[i].name >> stu[i].score;//����
	}

	for (int i = 1; i < n ; i++)
		for (int j = 1; j < n ; j++)
			if (stu[j].score < stu[j + 1].score) {
				stu[0] = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = stu[0];//ð������
			}

	for (int i = 1; i < n + 1; i++) {
		cout << stu[i].name << ' ' << stu[i].score << endl;//���
	}

	return 0;
}