#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char a[100];
	int j = 0, n, d, t, i = 0;
	cin.getline(a, 2000, '\n');
	for (; i < 100; i++) {
		if (a[i] == '\0')
			break;
		if (a[i] <= 'Z' && a[i] >= 'A') {
			a[i] = a[i] + 32;
			cout << a[i];
		} else if (a[i] <= 'z' && a[i] >= 'a') {
			a[i] = a[i] - 'a' + 1;
			cout << (int)a[i];
		}

		else if (a[i] == ' ') {
			a[i] = '*';
			cout << a[i];
		} else {
			j++;

		}

	}
}