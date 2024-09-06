#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class COMPLEX {
		friend istream &operator>>(istream &cin, COMPLEX &a);
		friend ostream &operator<<(ostream &cout, COMPLEX &a);
	public:
		double m_a;
		double m_b;
		COMPLEX(double a = 0, double b = 0) {
			m_a = a;
			m_b = b;
		}
		COMPLEX operator+(COMPLEX &a) {
			COMPLEX temp;
			temp.m_a = this->m_a + a.m_a;
			temp.m_b = this->m_b + a.m_b;
			return temp;
		}

};

COMPLEX operator+(COMPLEX &a, double b) {
	COMPLEX temp;
	temp.m_a = a.m_a + b;
	temp.m_b = a.m_b;
	return temp;
}

COMPLEX operator+(double b, COMPLEX &a) {
	COMPLEX temp;
	temp.m_a = a.m_a + b;
	temp.m_b = a.m_b;
	return temp;
}

istream &operator>>(istream &cin, COMPLEX &a) {
	char i;
	cin >> a.m_a >> a.m_b >> i;
	return cin;
}

ostream &operator<<(ostream &cout, COMPLEX &a) {
	cout << a.m_a;
	if (a.m_b < 0) {
		cout << a.m_b << 'i';
	} else {
		cout << "+" << a.m_b << 'i';
	}
	return cout;
}

int main() {
	COMPLEX a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << c << endl;
	return 0;
}