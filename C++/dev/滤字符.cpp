#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	char SweepedChar;
	for (int i = 0; i < n; i++) {
		cin >> str >> SweepedChar;
		int l = str.length();
		for (int j = 0; j < l; j++)
			if (str[j] == SweepedChar) {
				str.erase(j, 1);
				j--;
				l--;
			}
		if (l > 0)
			cout << str << endl;
		else
			cout << "NULL" << endl;

	}
}
