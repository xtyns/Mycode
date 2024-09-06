#include <iostream>
#include <string>
using namespace std;

class HugeInteger {
	public:
//int num;
		string line;
		HugeInteger() {
			this->line = "";
		}
		HugeInteger(int num) {
			this->line = to_string(num);
		}
		HugeInteger(string line) {
			this->line = line;
		}
};

ostream &operator<<(ostream &cout, HugeInteger p) {
	if (p.line != "")
		cout << p.line;
	else
		cout << '0';
	return cout;
}

string Addline(string a, string b) {
	string c;
	int la = a.size();
	int lb = b.size();
	if (la > lb) {
		for (; la != lb;) {
			b = "0" + b;
			lb++;
		}
	} else
		for (; la != lb;) {
			a = "0" + a;
			la++;
		}
	a = "0" + a;
	b = "0" + b;
	la++;
	lb++;
	for (int i = 0; i < la; i++) {
		c.push_back(a[i] + b[i] - '0');
	}
	for (int i = 0; i < la; i++) {
		if (c[i] >= '9') {
			c[i] -= 10;
			c[i - 1] += 1;
		}
	}
	if (c[0] == '0') {
		c.erase(0, 1);
	}
	return c;

}

HugeInteger operator + (HugeInteger &a, HugeInteger &b) {
	HugeInteger temp;
	temp.line = Addline(a.line, b.line);
	return temp;
}

HugeInteger operator + (HugeInteger &a, int b) {
	HugeInteger temp;
	temp.line = Addline(a.line, to_string(b))  ;
	return temp;
}

HugeInteger operator + (HugeInteger &a, string b) {
	HugeInteger temp;
	temp.line = Addline(a.line, b);
	return temp;
}


int main() {
	HugeInteger n1( 7654321 );
	HugeInteger n2( 7891234 );
	HugeInteger n3( "99999999999999999999999999999" );
	HugeInteger n4( "1" );
	HugeInteger n5;
	cout << "n1 is " << n1 << "\nn2 is " << n2
	     << "\nn3 is " << n3 << "\nn4 is " << n4
	     << "\nn5 is " << n5 << "\n\n";
	n5 = n1 + n2;
	cout << n1 << " + " << n2 << " = " << n5 << "\n\n";
	cout << n3 << " + " << n4 << "\n= " ;
	cout << ( n3 + n4 ) << "\n\n";
	n5 = n1 + 9;
	cout << n1 << " + " << 9 << " = " << n5 << "\n\n";
	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << endl;

	return 0;
}
