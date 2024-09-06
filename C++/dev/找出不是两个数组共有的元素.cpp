#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int> v1;
	int hold;
	for (int i = 0; i < n; i++) {
		cin >> hold;
		v1.push_back(hold);
	}
	cin >> m;
	vector<int> v2;
	for (int i = 0; i < m; i++) {
		cin >> hold;
		v2.push_back(hold);
	}
	vector<int>v3;

	auto it1 = v1.begin();
	for (; it1 != v1.end(); it1++) {
		int test(0);
		auto it2 = v2.begin();
		for (; it2 != v2.end(); it2++)
			if (*it1 == *it2) {
				test++;
			}
		if (test == 0)
			v3.push_back(*it1);
	}
	auto it2 = v2.begin();
	for (; it2 != v2.end(); it2++) {
		int test(0);
		it1 = v1.begin();
		for (; it1 != v1.end(); it1++)
			if (*it1 == *it2) {
				test++;
			}
		if (test == 0)
			v3.push_back(*it2);
	}

	it1 = v3.begin();
	for (; it1 != v3.end() - 1; it1++) {
		for (auto it2 = (it1 + 1); it2 != v3.end(); it2++) {
			if (*it1 == *it2) {
				v3.erase(it2);
				it1--;
				it2--;
			}
		}
	}
	it1 = v3.begin();
	for (; it1 != v3.end(); it1++) {
		cout << *it1 ;
		if (it1 != v3.end() - 1)
			cout << ' ';
	}
}



