#include <iostream>
using namespace std;

class CRAFT {

	protected:
		double speed;
	public:
		CRAFT(double x): speed(x) {

			cout << "创建航行器(速度: " << speed << ")" << endl;
		}
		virtual ~CRAFT() {
			cout << "销毁航行器(速度: " << speed << ")" << endl;
		}
		virtual void Show() {
			cout << "航行（速度：" << speed << ")" << endl;
		}
};

class PLANE: virtual public CRAFT {
	protected:
		double width;
	public:
		PLANE(double a, double b): CRAFT(a), width(b) {

			cout << "创建飞机(翼展: " << width << ")" << endl;
		}
		virtual ~PLANE() {
			cout << "销毁飞机(翼展: " << width << ")" << endl;
		}
		virtual void Show() {
			cout << "航行（速度：" << speed << ",翼展：" << width << ")" << endl;
		}
};

class SHIP: virtual public  CRAFT {
	protected:
		double depth;
	public:
		SHIP(double a, double b): CRAFT(a), depth(b) {

			cout << "创建船(吃水: " << depth << ")" << endl;
		}
		virtual ~SHIP() {
			cout << "销毁船(吃水: " << depth << ")" << endl;
		}
		virtual void Show() {
			cout << "航行（速度：" << speed << ",吃水：" << depth << ")" << endl;
		}
};

class SEAPLANE: public PLANE, public SHIP {
	public:
		virtual void Show() {
			cout << "航行（速度：" << speed << ",翼展：" << width << ",吃水：" << depth << ")" << endl;
		}
		SEAPLANE(double a, double b, double c): CRAFT(a), PLANE(a, b), SHIP(a, c) {
			cout << "创建水上飞机" << endl;
		}
		virtual ~SEAPLANE() {
			cout << "销毁水上飞机" << endl;
		}
};

int main() {
	CRAFT *p;
	p = new SHIP(45.8, 8.3);
	p->Show();
	delete p;

	return 0;
}
