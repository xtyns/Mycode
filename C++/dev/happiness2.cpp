#include <iostream>
#include <cmath>
using namespace std;
int cc[10001];
int n, m;

//判断素数
int sushu(int x) {
	if (x == 1)
		return 0;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

//求各位平方和
int pingfanghe(int x) {
	int m = 0;
	if (x == 10000)
		return 1;
	int a1, a2, a3, a4;
	a1 = x / 1000;
	a2 = x / 100 % 10;
	a3 = x % 100 / 10;
	a4 = x % 10;
	m = a1 * a1 + a2 * a2 + a3 * a3 + a4 * a4;
	return m;
}

//已知是幸福数，判断他是否独立
int duli(int x) {
	int i;
	//如果有别的数的各位平方数是它，那它就不是特立独行的
	for (i = n; i <= m; i++) {
		if (cc[i] == x)
			return 0;
	}
	return 1;
}

// 判断是否是幸福数
int xingfu(int x) {
	int p[10001];
	int i, j;
	int a = x;
	for (i = 0; cc[a] != 1; i++) {
		p[i] = cc[a];
		a = cc[a];
		for (j = 0; j < i; j++) {
			if (p[j] == p[i])
				return 0;
		}
	}
	return 1;
}

int main() {
	int i, flag = 0, count, x;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= 10000; i++) {
		cc[i] = pingfanghe(i);
	}
	for (i = n; i <= m; i++) {
		if (duli(i) && xingfu(i)) {
			printf("%d ", i);
			//根据题意哪怕没有数依附，独立性也是1
			count = 1;
			x = i;
			while (pingfanghe(x) != 1) {
				count++;
				x = pingfanghe(x);
			}
			if (sushu(i)) {
				count *= 2;
			}
			printf("%d\n", count);
			flag = 1;
		}
	}
	if (!flag)
		printf("SAD");
	return 0;
}
