#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ifprime(int a) {
	for (int i = 2; i < int(sqrt(a)) + 1; i++)
		if (a % i == 0)
			return 0;
	if (a < 2)
		return 0;
	return 1;
}

int main() {
	cout << ifprime(7);
	int L, K;
	cin >> L >> K;
	string str;
	cin >> str;
	for (int i = 0; i < L - K + 1; i++) {
		int num = stoi(str.substr(i, K));
		if (ifprime(num) == 1) {
			cout << str.substr(i, K) ;
			return 0;
		}
	}
	cout << "404" ;
	return 0;
}