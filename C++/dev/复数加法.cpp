#include <iostream>
using namespace std;

class plural {
	protected:
		double rm;
		double im;
	public:
		plural operator+(plural &z) {
			plural temp;
			temp.rm = this->rm + z.rm;
			temp.im = this->im + z.im;
			return temp;
		}
		void SetPlural() {
			cout << "���븴����ʵ��:";
			cin >> rm ;
			cout << "���븴�����鲿:";
			cin >> im;
		}
		void PrintPlural() {
			cout << "�ø���ʵ��Ϊ��" << rm << "; �鲿Ϊ��" << im;
		}
};

int main() {
	plural z1, z2, z3;
	z1.SetPlural();
	z2.SetPlural();
	z3 = z1 + z2;
	z3.PrintPlural();
	return 0;
}
