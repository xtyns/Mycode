#include <iostream>
#include <string>
using namespace std;

int main() {
	int ifallpass(1);
	int n;
	cin >> n;
	string str;
	int por[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	for (int i = 0; i < n; i++) {
		int test(0);

		cin >> str;
		int sum(0);
		for (int j = 0; j < 17; j++) {
			if (!(str[j] >= '0' && str[j] <= '9')) {
				cout << str << endl;
				test = 1;
				ifallpass = 0;
				break;
			}
			sum += (str[j] - '0') * por[j];
		}
		int Z = sum  % 11;
		if (M[Z] != str[17] && test == 0) {
			cout << str << endl;
			ifallpass = 0;
		}

	}
	if (ifallpass == 1)
		cout << "All passed" << endl;
	return 0;
}
