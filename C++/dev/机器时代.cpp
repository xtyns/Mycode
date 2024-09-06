#include <iostream>
#include <string>
using namespace std;

int main() {
	char c;
	string PC = "";
	int n = 0;
	while (cin.get(c)) {
		if (c == '\n') {
			break;
		}
		PC += c;
		n++;
	}
	char PD[n] = {'0'};
	int pos = 0;
	char POW = '0';
	for (int j = 0; j < n; j++) {
		if (POW == '0')
			POW = PC[j];
		switch (POW) {
			case '0':
				cout.put(PD[pos]);
				break;
			case '1':
				cin.get(c);
				PD[pos] = c;
				break;
			case '2':
				PD[pos]++;
				break;
			case '3':
				PD[pos]--;
				break;
			case '4':
				pos++;
				break;
			case '5':
				pos--;
				break;
			case '6':
				if (PD[pos] == 0) {
					pos++;
					POW = '7';
					j++;
					continue;
				}
				break;
			case '7':
				if (PD[pos] != 0) {
					pos--;
					POW = '6';
					j--;
					continue;
				}
				break;
		}
		POW = '0';

	}

	return 0;
}
