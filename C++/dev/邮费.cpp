#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int a, btype;
	double bprice;
	char c;
	double discount;
	cin >> a;
	cin >> btype;
	switch (btype) {
		case 90:
			bprice = 6.95;
			break;
		case 93:
			bprice = 7.44;
			break;
		case 97:
			bprice = 7.93;
			break;
	}
	cin >> c;
	switch (c) {
		case 'm':
			discount = 0.05;
			break;
		case 'e':
			discount = 0.03;
			break;
	}
	cout << fixed << setprecision(2) << 1.0 * a *bprice *(1 - discount);
	return 0;
}