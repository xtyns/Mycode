#include <iostream>
using namespace std;

bool b_is_true() {
	// 判断b说的是不是真话
	return true;
}

bool two_are_true() {
	// 判断是否有两个人说了真话
	return true;
}

bool one_is_criminal(char c) {
	// 判断c是否符合一个人是罪犯
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

