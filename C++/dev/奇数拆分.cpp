#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isprime(int s) {
	for (int i = 2; i <= sqrt(s); i++) {
		if (s % i == 0)
			return false;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int p;
		cin >> p;
		vector<int> v;//int *v=int v[p];
		for (int i = 2; i < p; i++) {
			if (isprime(i) == true) {
				v.push_back(i);
			}
		}
		int size = v.size();
		int typenum = 0;
		for (int j1 = 0; j1 < size; j1++) {
			for (int j2 = 0; j2 < size; j2++) {
				for (int j3 = 0; j3 < size; j3++) {
					if (v[j1] + v[j2] + v[j3] == p)
						typenum++;
				}
			}
		}
		cout << typenum << endl;
	}
	return 0;
}
