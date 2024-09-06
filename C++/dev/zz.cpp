#include <iostream>
using namespace std;

class CRAFT {
	protected:
		double speed;
	public:
		CRAFT(double s) {
			speed = s;
			cout << "����������(�ٶ�: " << speed << ')' << endl;

		}
		virtual void Show() {
			cout << "����(�ٶ�: " << speed << ')' << endl;
		}
		virtual ~CRAFT() {
			cout << "���ٺ�����(�ٶ�: " << speed << ')' << endl;
		}
};

class PLANE: virtual public CRAFT {
	protected:
		double width;
	public:
		PLANE(double s, double w): CRAFT(s), width(w) {
			cout << "�����ɻ�(��չ: " << width << ')' << endl;
		}
		virtual ~PLANE() {
			cout << "���ٷɻ�(��չ: " << width << ')' << endl;
		}
		virtual void Show() {
			cout << "����(�ٶ�: " << speed << ", ��չ: " << width << ')' << endl;
		}
};

class SHIP: virtual public CRAFT {
	protected:
		double depth;
	public:
		SHIP(double s, double d): CRAFT(s), depth(d) {
			cout << "������(��ˮ: " << depth << ')' << endl;
		}
		virtual void Show() {
			cout << "����(�ٶ�: " << speed << ", ��ˮ: " << depth << ')' << endl;
		}
		virtual ~SHIP() {
			cout << "���ٴ�(��ˮ: " << depth << ')' << endl;
		}
};

class SEAPLANE: public PLANE, public SHIP {/*����̳е�˳��Ҫ��PLANE��SHIP�����ܵõ���������Ľ��*/
	public:
		SEAPLANE(double s, double w, double d): CRAFT(s),  PLANE(s, w), SHIP(s, d) {
			cout << "����ˮ�Ϸɻ�" << endl;
		}
		virtual ~SEAPLANE() {
			cout << "����ˮ�Ϸɻ�" << endl;
		}
		virtual void Show() {
			cout << "����(�ٶ�: " << speed << ", ��չ: " << width << ", ��ˮ: " << depth << ')' << endl;
		}
};

int main() {
	double s, w, d;
	CRAFT *p;
	cin >> s >> w >> d;
	p = new SEAPLANE(s, w, d);
	p->Show();
	delete p;
	return 0;
}
