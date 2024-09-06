#include <iostream>
using namespace std;

class country {
	public:
		int code;
		int amount;
		int Ttimes;
		void setnum(int a, int b, int c)	 {
			code = a;
			amount = b;
			Ttimes = c;
		}
		void addnum(int a) {
			amount += a;
			Ttimes++;
		}
		void trade(country &a, country &b, int money);
		void print() {
			cout << code << ' ' << amount << endl;
		}

};

void trade(country &a, country &b, int money) {
	a.addnum(money);
	b.addnum(-money);
}

int main() {
	int n;
	cin >> n;
	country c[n];
	for (int i = 0; i < n; i++) {
		c[i].setnum(i + 1, 0, 0);
	}


	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int mcode, money;
			cin >> mcode >> money;
			trade(c[i], c[mcode - 1], money);
		}
	}


	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (c[j].amount < c[j + 1].amount) {
				country temp;
				temp = c[j + 1];
				c[j + 1] = c[j];
				c[j] = temp;
			}
			if (c[j].amount == c[j + 1].amount && c[j].Ttimes < c[j + 1].Ttimes) {
				country temp;
				temp = c[j + 1];
				c[j + 1] = c[j];
				c[j] = temp;
			}
			if (c[j].amount == c[j + 1].amount && c[j].Ttimes == c[j + 1].Ttimes && c[j].Ttimes > c[j + 1].Ttimes) {
				country temp;
				temp = c[j + 1];
				c[j + 1] = c[j];
				c[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		c[i].print();
	}
	return 0;
}
