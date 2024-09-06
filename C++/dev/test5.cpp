#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int n;
	cin >> n;
	char arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int l = str.size();
	for (int i = 0; i < l; i++) {
		if (str[i] <= 'z' && str[i] >= 'a') {
			str[i] = str[i] - 'a' + 'A';
		}
	}
	for (int i = 0; i < l; i++) {
		int test(0);
		for (int j = 0; j < n; j++) {

			if (str[i] == arr[j]) {
				break;

			}
			test++;
		}
		if (test == n) {
			str.erase(i, 1);
			l--;
			i--;
		}
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < n; j++) {
			if (str.find(arr[j]) != string::npos) {
				cout << arr[j];
				str.erase(str.find(arr[j]), 1);
				l--;
				i--;
			}
		}

	}
}
