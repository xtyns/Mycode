#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double m, h;
	cin >> m >> h;
	cout << "BMI is " << fixed << setprecision(4) << m / h / h << endl;
}