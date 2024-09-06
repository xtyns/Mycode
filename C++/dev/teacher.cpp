#include <iostream>
#include <string>
using namespace std;

class Teacher {
	private:
		string name;
		int age;
	public:
		Teacher(string name, int age);
		string getName() const;
		int getAge() const ;
		void setName(string name);
		void setAge(int age);
};

Teacher::Teacher(string name, int age) {
	this->name = name;
	this->age = age;
}

string Teacher:: getName()const {
	return name;
}

int Teacher::getAge() const {
	return age;
}

void Teacher::setName(string name) {
	this->name = name;
}

void Teacher::setAge(int age) {
	this->age = age;
}

int main() {
	Teacher a("Wang", 20);
	cout << "name:" << a.getName() << endl;
	cout << "age:" << a.getAge() << endl;
	a.setName("Zhang");
	a.setAge(30);
	cout << "name:" << a.getName() << endl;
	cout << "age:" << a.getAge() << endl;
	return 0;
}