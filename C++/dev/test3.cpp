#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//遍历数组vector，修改vector里的所有元素值为5,输出元素
void fn(int &item)
{
	item = 5;
	cout << item << endl; 
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	vector<int> v(a,a+7);
	
	for_each(v.begin(),v.end(),fn);
} 
