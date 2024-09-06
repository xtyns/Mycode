#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	cin.ignore();
	int l;
	for (; n > 0; n--) {
		getline(cin, str);
		l = str.length();
		int idx1 = str.find(',');
		if (idx1 < 3) {
			cout << "Skipped" << endl;
			continue;
		}
		bool f1 = str.substr(idx1 - 3, 3) == "ong";
		int idx2 = str.find('.');
		bool f2 = str[idx2 - 1] == 'g' && str[idx2 - 2] == 'n' && str[idx2 - 3] == 'o';



//		bool f1 = str[idx1-1] == 'g' && str[idx1-2] == 'n' && str[idx1-3] == 'o';
//		int idx2 = str.find('.');
//		bool f2 = str[idx2-1] == 'g' && str[idx2-2] == 'n' && str[idx2-3] == 'o';

//		restr = str;
//		restr.replace(l - 4, 3, "ong");
//		int dot = str.find(',');
//		str.replace(dot - 3, 3, "ong");

		int space = 0;
		int j = l - 2;
		for (; space != 3; j--) {
			if (str[j] == ' ')
				space++;
		}

		if (f1 && f2)
			cout << str.replace(j + 2, l - j - 2, "qiao ben zhong.") << endl;
//		if (restr == str )
//			cout << restr.replace(j + 2, l - j - 2, "qiao ben zhong.") << endl;
		else
			cout << "Skipped" << endl;
	}
	return 0;
}