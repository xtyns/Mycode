#include <iostream>
#include <cmath>
using namespace std;

int sushu(int a) {
	for (int i = 2; i < int(sqrt(a)); i++)
		if (a % i == 0)
			return 0;
	if (a < 2)
		return 0;
	return 1;
}

int main() {
	int sushu(int N);
	int N;
	cin >> N;
	if (sushu(N) == 0)
		cout << "不是素数";
	else
		cout << "是素数";
	return 0;
}