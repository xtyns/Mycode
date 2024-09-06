#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int n;
	cin >> n;
	double arr[2][n];
	for (int i = 0; i < n; i++) {
		cin >> arr[0][i] >> arr[1][i];
	}
	double dist = 0;
	double miniDist = distance(arr[0][0], arr[1][0], arr[0][1], arr[1][1]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				j++;
			dist = distance(arr[0][i], arr[1][i], arr[0][j], arr[1][j]);
			miniDist = dist < miniDist ? dist : miniDist;
		}
	int p1, p2;
	int i = 0;
	int j = 0;
	for (; i < n; i++) {
		for (; j < n; j++) {
			if (i == j)
				j++;
			dist = distance(arr[0][i], arr[1][i], arr[0][j], arr[1][j]);
			if (miniDist == dist) {
				p1 = i;
				p2 = j;
				break;
			}
		}
		if (miniDist == dist) {
			break;
		}
	}
	cout << fixed << setprecision(2);
	if (arr[0][p1] + arr[1][p1] > arr[1][p1] + arr[0][p2]) {
		int temp = p1;
		p1 = p2;
		p2 = temp;
	}
	cout << '(' << arr[0][p1] << "," << arr[1][p1] << "),(" << arr[0][p2] << "," << arr[1][p2] << ')' << ",miniDist=" <<
	     setprecision(3) << miniDist;
	return 0;
}
