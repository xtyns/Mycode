#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int N;
	cin >> N;
	int *grade;
	grade = new int[N];
	cin >> *grade;
	double max, min;
	max = * grade;
	min = *grade;
	int sum = *grade;
	for (int i = 1; i < N; i++) {
		cin >> * (grade + i);
		sum += * (grade + i);
		max = max > *(grade + i) ? max : *(grade + i);
		min = min < *(grade + i) ? min : *(grade + i);
	}
	double avg = 1.0 * sum / N;
	cout << fixed << setprecision(2);
	cout << "average = " << avg << endl;
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;

	return 0;
}
