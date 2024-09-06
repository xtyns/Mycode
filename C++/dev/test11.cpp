#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class COMPLEX {
	public:
		double real;
		double imag;
		COMPLEX(double a = 0, double b = 0) {
			real = a;
			imag = b;
		}
};

istream &operator>>(istream &is, COMPLEX &z) {
	string temp;
	getline(cin, temp);
	int pos;
	if ((pos = temp.find('+')) != string::npos) {
		pos = temp.find('+');
	} else {
		pos = temp.find('-');
	}

	z.real = stod(temp.substr(0, pos));
	z.imag = stod(temp.substr(pos + 1, temp.find('i') - pos - 1));
	return is;
}

ostream &operator<<(ostream &os, COMPLEX &z) {
	os << z.real;
	if (z.imag >= 0)
		os << "+";
	os << z.imag << "i";
	return os;
}

COMPLEX operator+(COMPLEX z1, COMPLEX z2) {
	COMPLEX temp;
	temp.real = z1.real + z2.real;
	temp.imag = z1.imag + z2.imag;
	return temp;
}

int main() {
	COMPLEX a(3, 4), b(2, -7), c(-1, 8), d;
	d = a + b + c;
	cout << d << endl;
	return 0;
}