#include <iostream>
using namespace std;

class Teacher {
	private:
		string name; //姓名
		string course; //所教课程
	public:
		Teacher() {};
		Teacher(string name_, string course_);
		string getName() {
			return name;
		}
		string getCourse() {
			return course;
		}
};

Teacher::Teacher(string name_, string course_): name(name_), course(course_) {
}

class Class {
	private:
		int _grade;
		int _class;
		Teacher *p;
	public:
		Class(int g, int c, string n_ = "unknow", string c_ = "chinese"): _grade(g), _class(c) {
			p = new Teacher(n_, c_);
			cout << "grade:" << _grade << " class no:" << _class << ",head teacher:" << p->getName() << "(" << p->getCourse() << ")"
			     << endl;
		}
		Class() {
			cout << "new class created" << endl;
		}

};

int main() {
	system("cls"); // 清屏
	Class c1(2, 1, "ZhangXiaowen", "math");
	Class c2(3, 2, "LiSisi");
	Class c3(1, 1);
	Class c4;
	return 0;
}
