#include <iostream>
#include <string>
using namespace std;

class list {
	public:
		void coutapp();
		int bnum;
		string id;
		int weight;
		int diameter;
};

void list::coutapp() {
	cout << bnum << ' ' << id << ' ' << weight << ' ' << diameter << endl;
}

int main() {
	int n;
	cin >> n;
	list apple[n];
	for (int i = 0; i < n; i++)
		cin >> apple[i].bnum >> apple[i].id >> apple[i].weight >> apple[i].diameter;
	int min_bnum = apple[0].bnum, max_bnum = apple[0].bnum;
	for (int i = 0; i < n; i++) {
		min_bnum = min_bnum < apple[i].bnum ? min_bnum : apple[i].bnum;
		max_bnum = max_bnum > apple[i].bnum ? max_bnum : apple[i].bnum;
	}
	for (int i = min_bnum; i <= max_bnum; i++) {
		int mwet = 0;
		for (int j = 0; j < n; j++) {
			if (apple[j].bnum == i) {
				mwet = mwet > apple[j].weight ? mwet : apple[j].weight;
			}
		}
		for (int j = 0; j < n; j++) {
			if (apple[j].weight == mwet && apple[j].bnum == i) {
				{
					apple[j].coutapp();
					break;
				}
			}
		}
	}
	return 0;
}
