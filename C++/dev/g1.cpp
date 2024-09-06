#include <iostream>
using namespace std;

class CPU {
	protected:
		int rank;
		int frequency;
		int voltage;

	public:
		CPU(int r, int f, int v) {
			rank = r;
			frequency = f;
			voltage = v;
			cout << "create a CPU!" << endl;
		}
		CPU(CPU cpu) {
			this->rank = cpu.rank;
			this->frequency = cpu.frequency;
			this->voltage = cpu.voltage;
			cout << "create a CPU by copy!" << endl;
		}
		~CPU() {
			cout <<	"desturct a CPU!" << endl;
		}

};

class RAM {
	protected:
		double volumn;
	public:
		RAM(double r): volumn(r) {
			cout << "create a RAM!" << endl;
		}
		RAM(RAM &ram) {
			this->volumn = ram.volumn;
			cout << "create a RAM by copy!" << endl;
		}
		~RAM() {
			cout <<	"desturct a RAM!" << endl;
		}
};

class CDROM {
	protected:
		int speed;
	public:
		CDROM(int d): speed(d) {
			cout << "create a CDROM!" << endl;
		}
		CDROM(CDROM &cd) {
			this->speed = cd.speed;
			cout << "create a CDROM by copy!" << endl;
		}
		~CDROM() {
			cout <<	"desturct a COROM!" << endl;
		}
};

class COMPUTER: public CPU, public RAM, public CDROM {

	public:
		COMPUTER(int r1 = 1, double f = 2, int v = 100, double r2 = 1, int d = 16): CPU(r1, f, v), RAM(r2), CDROM(d) {
			if (r1 == 1 && f == 2 && v == 100 && r2 == 1 && d == 16) {
				cout << "no para to create a COMPUTER!" << endl;
			} else
				cout << "create a COMPUTER with para!" << endl;
		}
		COMPUTER(COMPUTER &com) {
			COMPUTER.CPU(CPU(com.rank, com.frequency, com.voltage));
			COMPUTER.RAM(RAM(com.volumn));
			COMPUTER.CDROM(CDROM(com.speed));


			cout << "create a COMPUTER by copy!" << endl;

		}
		void run();
		void stop();
		void showinfo() {
			cout << "cpu parameter:" << endl;
			cout << "rank:" << rank << endl;
			cout << "frequency:" << frequency << endl;
			cout << "voltage:" << voltage << endl;
			cout << "ram parameter:" << endl;
			cout << "volumn:" << volumn << " GB" << endl;
			cout << "cdrom parameter:" << endl;
			cout << "speed:" << speed << endl;
		}

};


int main() {
	COMPUTER cpt1(6, 4.0, 200, 60, 32); //测试带参数构造
	cout << "cpt1's parameter:" << endl;
	cpt1.showinfo();
	cout << "------------------------------" << endl;
	COMPUTER cpt2; //测试不带参数构造
	cout << "cpt2's parameter:" << endl;
	cpt2.showinfo();
	cout << "------------------------------" << endl;
	COMPUTER cpt3(cpt1); //测试复制构造
	cout << "cpt3's parameter:" << endl;
	cpt3.showinfo();
	cout << "------------------------------" << endl;
}

