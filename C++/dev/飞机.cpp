#include <iostream>
using namespace std;

class CRAFT {
	protected:
		double speed;
	public:
		CRAFT(double v) {
			speed = v;
			cout << "����������(�ٶ�: " << speed << ")" << endl;
		}
		virtual	~CRAFT() {
			cout << "���ٺ�����(�ٶ�: " << speed << ")" << endl;
		};
		virtual void Show() {
			cout << "����(�ٶ�: " << speed << ")" << endl;
		}
};



class PLANE : virtual public CRAFT {
	protected:
		double width;
	public:
		PLANE(double v = 0, double w = 0) : CRAFT(v), width(w) {
			cout << "�����ɻ�(��չ: " << width << ")" << endl;
		}

		virtual ~PLANE() {
			cout << "���ٷɻ�(��չ: " << width << ")" << endl;
		}

		virtual void Show() {
			cout << "����(�ٶ�: " << speed << ", ��չ: " << width << ")" << endl;
		}
};

class SHIP : virtual public CRAFT {
	protected:
		double depth;
	public:
		SHIP(double v, double d) : CRAFT(v), depth(d) {
			cout << "������(��ˮ: " << depth << ")" << endl;
		}

		virtual ~SHIP() {
			cout << "���ٴ�(��ˮ: " << depth << ")" << endl;
		}

		virtual void Show() {
			cout << "����(�ٶ�: " << speed << ", ��ˮ: " << depth << ")" << endl;
		}
};

class SEAPLANE : public PLANE, public SHIP {
	public:

		SEAPLANE(double v, double w, double d) : CRAFT(v), PLANE(v, w), SHIP(v, d) {
			cout << "����ˮ�Ϸɻ�" << endl;
		}

		virtual ~SEAPLANE() {
			cout << "����ˮ�Ϸɻ�" << endl;
		}

		virtual void Show() {
			cout << "����(�ٶ�: " << speed << ", ��չ: " << width << ", ��ˮ: " << depth << ")" << endl;
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
