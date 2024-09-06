#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int conum(int y) {
	string str = to_string(y);
	int l = str.length();
	for (; l != 4; l++)
		str = '0' + str;
	int test(0);
	for (int i = 0; i < l; i++)
		for (int j = i + 1; j < l; j++)
			if (str[i] == str[j])
				test++;
	return test;
}

int main() {
	int y, n, age(0);
	cin >> y >> n;
	for (; n > 0;) {
		if (n == 4 && conum(y) == 0) {
			break;
		}
		if (n == 3 && conum(y) == 1) {
			break;
		}
		if (n == 2 && (conum(y) == 3 || conum(y) == 2)) {
			break;
		}
		age++;
		y++;
	}
	cout << setfill('0');
	cout << age << " " << setw(4) << y;
}