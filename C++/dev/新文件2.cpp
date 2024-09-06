#include <iostream>
#include <string>
using namespace std;

int main() {
	int arr[10];
	int hold, test(1);
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	while (test != 0) {
		test = 0;
		for (int i = 0; i < 10; i++) {
			if (arr[i] > arr[i + 1]) {
				hold = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = hold;
				test++;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << "   ";

	return 0;
}