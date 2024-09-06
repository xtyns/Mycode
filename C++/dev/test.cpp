#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class COMPLEX {
	public:
		double r;
		double i;
		COMPLEX(double a = 0, double b = 0) {
			r = a;
			i = b;
		}

};

istream &operator>>(istream &is, COMPLEX &z) {
	string temp;
	cin >> temp;
	int pos;
	if (temp.find('+') != -1) {
		pos = temp.find('+');
	} else
		pos = temp.find('-');

	z.r = stod(temp.substr(0, pos));
	z.i = stod(temp.substr(pos, temp.find('i') - pos));
	return is;
}

ostream &operator<<(ostream &os, COMPLEX &z) {
	os << z.r ;
	if (z.i >= 0)
		os << "+";
	os << z.i << "i";
	return os;
}

COMPLEX operator+(COMPLEX z1, COMPLEX z2) {
	COMPLEX temp;
	temp.r = z1.r + z2.r;
	temp.i = z1.i + z2.i;
	return temp;
}

int main() {
	COMPLEX a(3, 4), b(2, -7), c(-1, 8), d;
	d = a + b + c;
	cout << d << endl; // Êä³ö: 4+5i
}