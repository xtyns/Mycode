#include <iostream>
using namespace std;

class Pig {
	public:
		Pig() {
			cout << "Pig �����˿ռ�..." << endl;
		}
		virtual ~Pig() {
			cout << "Pig �ͷ��˿ռ�..." << endl;
		}
		virtual void climb() {
			cout << "��ֻ�Ǹ�ƽ��������" << endl;
		}
};

class MagicPig: public Pig {
	public:
		MagicPig() {
			cout << "MagicPig �����˿ռ�..." << endl;
		}
		virtual ~MagicPig() {
			cout << "MagicPig �ͷ��˿ռ�..." << endl;
		}
		virtual void climb() {
			cout << "����������Ү��" << endl;
		}
};

int main() {
	Pig *p1 = new Pig;
	Pig *p2 = new MagicPig;
	cout << endl;

	p1->climb();
	p2->climb();
	cout << endl;

	delete p1;
	delete p2;
	return 0;
}