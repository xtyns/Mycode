#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	int rmax[n], rmin[n];
	for (int i = 0; i < n; i++)
	{
		rmax[i] = arr[i][0];
		for (int j = 0; j < n; j++)
		{
			rmax[i] = rmax[i] > arr[i][j] ? rmax[i] : arr[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		rmin[j] = arr[0][j];
		for (int i = 0; i < n; i++)
		{
			rmin[j] = rmin[j] < arr[i][j] ? rmin[j] : arr[i][j];
		}
	}
	int test(0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == rmax[i] && arr[i][j] == rmin[j])
			{
				cout << i << ' ' << j << endl;
				test++;
			}
	if (test == 0)
		cout << "NONE";

	return 0;
}