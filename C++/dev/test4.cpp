#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
	vector<int>v;
	srand((unsigned int)time(NULL));
	for (int i = 1; i <= 100; i++)
		v.push_back((rand() % 100 ));
//	cout << '1' << endl;;
//	cout << (int)char(1) << endl;
//	cout << char(49) << endl;
//	cout << char(1) << endl;
	sort(v.begin(), v.end());

	auto it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	auto it1 = min_element(v.begin(), v.end());
	auto it2 = max_element(v.begin(), v.end());
	cout << endl << *it1 << endl;
	cout << *it2 << endl;
//	cout << endl;
//	cout << (int)v.front() << " " << (int) v.back();
	return 0;
}
