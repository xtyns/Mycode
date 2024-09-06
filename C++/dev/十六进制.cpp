#include <iostream>
using namespace std;

int main() {

	unsigned int v;
	cin >> v;
	cout << hex;
	cout << v << endl;
	unsigned char *p = (unsigned char *)&v;
	for (int i = 0; i < 4; i++) {
		cout << int(p[i]);
		if (i != 3) {
			cout << " ";
		}
	}
	return 0;
}