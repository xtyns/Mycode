#include <iostream>
#include <iomanip>
using namespace std;
//8m=all+km
//6n=all+kn
//10sx=all+kx


int main() {
	double m, n;
	cin >> m >> n;
	int all = (8 * m * n - 6 * m * n) / (n - m);
	int k = (8 * m - 6 * n) / (-n + m);
	double x = 1.0 * all / (10 - k);
	cout << fixed << setprecision(1);
	cout << "Original number of visitors: " << all << endl;
	cout << "New arriavlas per minute: " << k << endl;
	cout << "Check time when 10 gates are opened: " << x << endl;

	return 0;
}
