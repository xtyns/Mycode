#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//��������vector���޸�vector�������Ԫ��ֵΪ5,���Ԫ��
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
