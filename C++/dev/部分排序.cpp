#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	vector<int> v;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	if (r + r < n)
		sort(v.begin() + r, v.end() - r);
	auto it = v.begin();
	for (; it != v.end(); ) {
		cout << *it ;
		it++;
		if (it != v.end())
			cout << ' ';
		else
			cout << endl;

	}
	return 0;
}