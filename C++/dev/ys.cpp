#include <iostream>
using namespace std;

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int *px = new int[n];
	int *py = new int[m];
	for (int i = 0; i < n; i++) {
		cin >> px[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> py[i];
	}
	int max[2] = {x, y};
	int min[2] = {x, y};
	for (int i = 0; i < n; i++) {
		max[0] = max[0] > px[i] ? max[0] : px[i];
		min[0] = min[0] < px[i] ? min[0] : px[i];
	}
	for (int i = 0; i < m; i++) {
		max[1] = max[1] > py[i] ? max[1] : py[i];
		min[1] = min[1] < py[i] ? min[1] : py[i];
	}
	if (y > x) {
		if (min[1] <= max[0]) {
			cout << x << " and " << y << ": possible" << endl;
		} else
			cout << x << " and " << y << ": impossible" << endl;
	} else {
		if (max[1] >= min[0]) {
			cout << x << " and " << y << ": possible" << endl;
		} else
			cout << x << " and " << y << ": impossible" << endl;
	}
}
