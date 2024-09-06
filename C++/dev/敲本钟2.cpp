#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	string str[22];
	string s = "qiao ben zhong."; //作为押韵替换字符串
	string t = "Skipped";  //作为不押韵替换字符串
	cin >> n;
	getchar();    //读掉输入n后的换行符
	for (int i = 0; i < n; i++) {
		getline(cin, str[i]);
		if (str[i].find("ong,") != string :: npos) { //如果返回不为npos 即可以找到“ong,” 上句押韵
			if (str[i].rfind("ong.") != string :: npos) { //如果返回不为npos 即可以找到“ong.” 下句押韵
				//寻找替换开始的位置
				int k = 0, f = 0;                //k为空格计数，f为替换长度计数
				unsigned int j = str[i].size();  //j从句末开始向前遍历
				for (; j > 0; j--) {
					if (k == 3)  //如果k==3即遇到第三个空格 跳出循环
						break;
					else if (str[i][j] == ' ')
						k++;
					f++;      //长度计数自增
				}
				str[i].replace(j + 2, f, s); //j为找到的空格的前一个字符，j+2为替换的开始，f为替换长度， s是要替换成的字符串
			} else
				str[i].replace(0, str[i].length(), t); //只有上句押韵的 全部替换为t串
		} else
			str[i].replace(0, str[i].length(), t);  //不押韵也同样替换成t串
	}
	for (int i = 0; i < n; i++) { //按顺序输出每句
		cout << str[i] << endl;
	}
	return 0;
}
