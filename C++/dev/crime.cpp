#include <iostream>
using namespace std;

bool b_is_true() {
	// �ж�b˵���ǲ����滰
	return true;
}

bool two_are_true() {
	// �ж��Ƿ���������˵���滰
	return true;
}

bool one_is_criminal(char c) {
	// �ж�c�Ƿ����һ�������ﷸ
	return true;
}

int main() {
	char criminal;

	if (b_is_true()) {
		criminal = 'c';
	} else {
		cout << "Error, cannot determine the criminal." << endl;
		return 0;
	}

	if (two_are_true() && one_is_criminal(criminal)) {
		cout << "The criminal is " << criminal << "." << endl;
	} else {
		cout << "Error, logic is incorrect." << endl;
	}

	return 0;
}

