#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	char c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cout << setfill(c) << setw(i + 1) << c << endl;
	}
}