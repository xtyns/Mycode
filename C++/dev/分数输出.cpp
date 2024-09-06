#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	double a, b, c, temp;
	int d1, d2;
	cin >> a;
	cin >> b;
	c = a / b;
	for (int j = 2; j < 100; j++) {
		for (int i = 1; i < 100; i++)
			if ( c * j - i == 0) {
				d1 = i;
				d2 = j;
				cout << d1 << '/' << d2;
				return 0;
			}
	}
	return 0;
}