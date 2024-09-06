#include <iostream>
#include <iomanip>
using namespace std;

bool ifnum(string str, char c) {
	if (str.find(c) != string::npos)
		return 1;
	return 0;
}

int main() {
	system("cls"); // 清屏
	string str;
	for (int i = 123; i < 1000; i++) {
		str = to_string(i);
		if (ifnum(str, '1') + ifnum(str, '2') + ifnum(str, '3') + ifnum(str, '4') == 3)
			cout << str << endl;
	}
}


