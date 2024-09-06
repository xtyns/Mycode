#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string ch;
	cin >> n >> ch;
	int sum(1);
	int ld(2);
	for (; sum + (2 * ld - 1) * 2 < n; ld++) {
		sum += (2 * ld - 1) * 2;
	}
	ld--;
	int ld2 = ld;
	for (int i = 0; i < ld2; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 0; j < 2 * ld - 1; j++) {
			cout << ch;
		}
		cout << endl;
		ld--;
	}
	for (int i = 2; i <= ld2; i++) {
		for (int j = 0; j < ld2 - i; j++)
			cout << ' ';
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << ch;
		}
		cout << endl;
	}
	cout << "Ê£Óà" << n - sum << "¸ö" << ch;

}