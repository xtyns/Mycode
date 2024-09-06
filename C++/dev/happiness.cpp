#include <iostream>
using namespace std;


int lone(int a) {
	for (int i = 2; i < a; i++)
		if (a % i == 0) {
			return 1;
		}
	return 2;
}

int hap(int a) {
	int result(0);
	for (; a > 0;) {
		result += (a % 10) * (a % 10);
		a /= 10;
	}
	return result;

}

int main() {
	int arr[10001] = {};
	int A, B;
	int ks, kx;
	int hapnum;
	int test(0);
	int loneif;
	int alone;
	int i;
	cin >> A >> B;
	for (int j = 1; j <= 10001; j++) {
		arr[j] = hap(j);
	}
	for (int k = A; k <= B; k++) {
		alone = 1;

		ks = k;
		kx = k;
		hapnum = 0;
		loneif = lone(k);
		for (i = A; i <= B; i++)
			if (k == arr[i])
				break;
		if (k == arr[i])
			continue;
		do {
			ks = arr[ks];
			hapnum++;
		} while (ks != kx && ks != 1 && hapnum != 13);


		if (ks == 1) {
			printf("%d %d\n", k, hapnum * loneif );
			test++;
		}
	}
	if (test == 0)
		cout << "SAD" << endl;
}


