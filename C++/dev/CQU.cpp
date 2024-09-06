#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int l = str.length();
	for (int i = 0; i < l; i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	char arr[3] = {'C', 'Q', 'U'};
	for (int i = 0; i < l; i++)
		for (int j = 0; j < 3; j++) {
			if (str.find(arr[j]) != string::npos) {
				cout << arr[j];
				str.erase(str.find(arr[j]), 1);
			}
		}
}