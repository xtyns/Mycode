#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string hold, namehold;
	vector<string> list;
	for (int i = 0; i < n; i++)
	{
		cin >> hold;

		if (hold == "in")
		{
			cin >> namehold;
			list.push_back(namehold);
		}
		if (hold == "out")
		{
			list.erase(list.begin());
		}
		if (hold == "q")
		{
			if (list.size() != 0)
			{

				cout << list[0] << endl;
			}
			else
				cout << "NULL" << endl;
		}
	}

	return 0;
}
