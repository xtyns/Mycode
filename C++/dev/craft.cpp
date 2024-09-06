#include <iostream>
using namespace std;

class CRAFT {

	protected:
		double speed;
	public:
		CRAFT(double x): speed(x) {

			cout << "����������(�ٶ�: " << speed << ")" << endl;
		}
		virtual ~CRAFT() {
			cout << "���ٺ�����(�ٶ�: " << speed << ")" << endl;
		}
		virtual void Show() {
			cout << "���У��ٶȣ�" << speed << ")" << endl;
		}
};

class PLANE: virtual public CRAFT {
	protected:
		double width;
	public:
		PLANE(double a, double b): CRAFT(a), width(b) {

			cout << "�����ɻ�(��չ: " << width << ")" << endl;
		}
		virtual ~PLANE() {
			cout << "���ٷɻ�(��չ: " << width << ")" << endl;
		}
		virtual void Show() {
			cout << "���У��ٶȣ�" << speed << ",��չ��" << width << ")" << endl;
		}
};

class SHIP: virtual public  CRAFT {
	protected:
		double depth;
	public:
		SHIP(double a, double b): CRAFT(a), depth(b) {

			cout << "������(��ˮ: " << depth << ")" << endl;
		}
		virtual ~SHIP() {
			cout << "���ٴ�(��ˮ: " << depth << ")" << endl;
		}
		virtual void Show() {
			cout << "���У��ٶȣ�" << speed << ",��ˮ��" << depth << ")" << endl;
		}
};

class SEAPLANE: public PLANE, public SHIP {
	public:
		virtual void Show() {
			cout << "���У��ٶȣ�" << speed << ",��չ��" << width << ",��ˮ��" << depth << ")" << endl;
		}
		SEAPLANE(double a, double b, double c): CRAFT(a), PLANE(a, b), SHIP(a, c) {
			cout << "����ˮ�Ϸɻ�" << endl;
		}
		virtual ~SEAPLANE() {
			cout << "����ˮ�Ϸɻ�" << endl;
		}
};

int main() {
	CRAFT *p;
	p = new SHIP(45.8, 8.3);
	p->Show();
	delete p;

	return 0;
}
