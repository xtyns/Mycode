#include <iostream>
using namespace std;

class CRAFT {
	protected:
		double speed;
	public:
		CRAFT(double s) {
			speed = s;
			cout << "创建航行器(速度: " << speed << ')' << endl;

		}
		virtual void Show() {
			cout << "航行(速度: " << speed << ')' << endl;
		}
		virtual ~CRAFT() {
			cout << "销毁航行器(速度: " << speed << ')' << endl;
		}
};

class PLANE: virtual public CRAFT {
	protected:
		double width;
	public:
		PLANE(double s, double w): CRAFT(s), width(w) {
			cout << "创建飞机(翼展: " << width << ')' << endl;
		}
		virtual ~PLANE() {
			cout << "销毁飞机(翼展: " << width << ')' << endl;
		}
		virtual void Show() {
			cout << "航行(速度: " << speed << ", 翼展: " << width << ')' << endl;
		}
};

class SHIP: virtual public CRAFT {
	protected:
		double depth;
	public:
		SHIP(double s, double d): CRAFT(s), depth(d) {
			cout << "创建船(吃水: " << depth << ')' << endl;
		}
		virtual void Show() {
			cout << "航行(速度: " << speed << ", 吃水: " << depth << ')' << endl;
		}
		virtual ~SHIP() {
			cout << "销毁船(吃水: " << depth << ')' << endl;
		}
};

class SEAPLANE: public PLANE, public SHIP {/*这里继承的顺序要先PLANE再SHIP，才能得到输出样例的结果*/
	public:
		SEAPLANE(double s, double w, double d): CRAFT(s),  PLANE(s, w), SHIP(s, d) {
			cout << "创建水上飞机" << endl;
		}
		virtual ~SEAPLANE() {
			cout << "销毁水上飞机" << endl;
		}
		virtual void Show() {
			cout << "航行(速度: " << speed << ", 翼展: " << width << ", 吃水: " << depth << ')' << endl;
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
