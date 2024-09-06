#include <iostream>
using namespace std;

class CRAFT {
	protected:
		double speed;
	public:
		CRAFT(double v) {
			speed = v;
			cout << "创建航行器(速度: " << speed << ")" << endl;
		}
		virtual	~CRAFT() {
			cout << "销毁航行器(速度: " << speed << ")" << endl;
		};
		virtual void Show() {
			cout << "航行(速度: " << speed << ")" << endl;
		}
};



class PLANE : virtual public CRAFT {
	protected:
		double width;
	public:
		PLANE(double v = 0, double w = 0) : CRAFT(v), width(w) {
			cout << "创建飞机(翼展: " << width << ")" << endl;
		}

		virtual ~PLANE() {
			cout << "销毁飞机(翼展: " << width << ")" << endl;
		}

		virtual void Show() {
			cout << "航行(速度: " << speed << ", 翼展: " << width << ")" << endl;
		}
};

class SHIP : virtual public CRAFT {
	protected:
		double depth;
	public:
		SHIP(double v, double d) : CRAFT(v), depth(d) {
			cout << "创建船(吃水: " << depth << ")" << endl;
		}

		virtual ~SHIP() {
			cout << "销毁船(吃水: " << depth << ")" << endl;
		}

		virtual void Show() {
			cout << "航行(速度: " << speed << ", 吃水: " << depth << ")" << endl;
		}
};

class SEAPLANE : public PLANE, public SHIP {
	public:

		SEAPLANE(double v, double w, double d) : CRAFT(v), PLANE(v, w), SHIP(v, d) {
			cout << "创建水上飞机" << endl;
		}

		virtual ~SEAPLANE() {
			cout << "销毁水上飞机" << endl;
		}

		virtual void Show() {
			cout << "航行(速度: " << speed << ", 翼展: " << width << ", 吃水: " << depth << ")" << endl;
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
