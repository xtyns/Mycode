#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str, restr;
	cin.ignore();
	int l;
	for (; n > 0; n--) {
		getline(cin, str);
		l = str.length();
		restr = str;
		restr.replace(l - 4, 3, "ong");
		int dot = str.find(',');
		str.replace(dot - 3, 3, "ong");
		int space(0);
		int j = l - 2;
		for (; space != 3; j--) {
			if (str[j] == ' ')
				space++;
		}

		if (restr == str )
			cout << restr.replace(j + 2, l - j - 2, "qiao ben zhong.") << endl;
		else
			cout << "Skipped" << endl;
	}
    return 0;
}