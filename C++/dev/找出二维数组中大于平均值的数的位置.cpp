#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, sum(0);
	cin >> n ;
	const int N = 20;
	int arr[N][N];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	double avg = 1.0 * sum / n / n;
	int test(0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > avg) {
				test++;
				cout << arr[i][j] << ' ' << i << ' ' << j << endl;
			}
		}
	if (test == 0)
		cout << '0';

}


