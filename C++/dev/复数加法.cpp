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
			cout << "输入复数的实部:";
			cin >> rm ;
			cout << "输入复数的虚部:";
			cin >> im;
		}
		void PrintPlural() {
			cout << "该复数实部为：" << rm << "; 虚部为：" << im;
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
