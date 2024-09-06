#include <iostream>
#include <iomanip>
using namespace std;

class COMPLEX {
	private:
		double r;
		double i;
	public:
		COMPLEX(double a = 0, double b = 0): r(a), i(b) {
		}
		COMPLEX operator+(COMPLEX &z);
		COMPLEX operator+(double z);
		friend istream &operator>>(istream &is, COMPLEX &z);
		friend ostream &operator<<(ostream &os, COMPLEX &z);

};

COMPLEX COMPLEX::operator+(COMPLEX &z) {
	return COMPLEX(this->r + z.r, this->i + z.i);
}

COMPLEX COMPLEX::operator+(double z) {
	return COMPLEX(this->r + z, this->i);
}

istream &operator>>(istream &is, COMPLEX &z) {
	is >> z.r >> z.i;
	cin.ignore();
	return is;
}

ostream &operator<<(ostream &os, COMPLEX &z) {
	cout << z.r;
	if (z.i >= 0)
		cout << '+';
	cout << z.i << 'i';

}

int main() {
	COMPLEX a(1, 1), b(1, 2), c(1, 3);
	c = a + b + c + 1.2;
	cout << c << endl;
	return 0;
}