#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	double e = 0;
	double factorial = 1;
	double term = 1;
	int i = 1;
	factorial *= 1.0 / i;
	for (; factorial >= 1 / pow(10, n); i++) {
		e += factorial;
		factorial *= 1.0 / i;
	}
	cout << fixed << setprecision(n + 1) << e << endl;

	return 0;
}