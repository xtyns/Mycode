#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	string str[22];
	string s = "qiao ben zhong."; //��ΪѺ���滻�ַ���
	string t = "Skipped";  //��Ϊ��Ѻ���滻�ַ���
	cin >> n;
	getchar();    //��������n��Ļ��з�
	for (int i = 0; i < n; i++) {
		getline(cin, str[i]);
		if (str[i].find("ong,") != string :: npos) { //������ز�Ϊnpos �������ҵ���ong,�� �Ͼ�Ѻ��
			if (str[i].rfind("ong.") != string :: npos) { //������ز�Ϊnpos �������ҵ���ong.�� �¾�Ѻ��
				//Ѱ���滻��ʼ��λ��
				int k = 0, f = 0;                //kΪ�ո������fΪ�滻���ȼ���
				unsigned int j = str[i].size();  //j�Ӿ�ĩ��ʼ��ǰ����
				for (; j > 0; j--) {
					if (k == 3)  //���k==3�������������ո� ����ѭ��
						break;
					else if (str[i][j] == ' ')
						k++;
					f++;      //���ȼ�������
				}
				str[i].replace(j + 2, f, s); //jΪ�ҵ��Ŀո��ǰһ���ַ���j+2Ϊ�滻�Ŀ�ʼ��fΪ�滻���ȣ� s��Ҫ�滻�ɵ��ַ���
			} else
				str[i].replace(0, str[i].length(), t); //ֻ���Ͼ�Ѻ�ϵ� ȫ���滻Ϊt��
		} else
			str[i].replace(0, str[i].length(), t);  //��Ѻ��Ҳͬ���滻��t��
	}
	for (int i = 0; i < n; i++) { //��˳�����ÿ��
		cout << str[i] << endl;
	}
	return 0;
}
