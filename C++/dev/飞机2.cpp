#include <iostream>
using namespace std;
class CRAFT{
	protected:
	double speed;
    public:
    	CRAFT(double v=0):speed(v){
		}
    	~CRAFT(){
		};
	}
	void Show(){
		cout<<"速度为"<<speed<<endl;
	}
};
class PLANE:public CRAFT{
	protected:
		double width;
		public:
			PLANE(double v=0,double w):speed(v),width(w){
			}
			~PLANEe(){
			}
			void Show(){
		cout<<"速度为"<<speed<<endl;
		cout<<"翼展为"<<width<<endl;
	}
};
class SHIP:public CRAFT{
	protected:
		double depth;
		public:
			SHIP(double v=0,double d):speed(v),width(d){
			}
				~SHIP(){
			}
			void Show(){
		cout<<"速度为"<<speed<<endl;
		cout<<"吃水深为"<<depth<<endl;
	}
};
class SEAPLANE:virtual public PLANE,virtual public SHIP{
	public:
		SEAPLANE(double v=0,double w,double d):speed(v),width(w),speed(v){
		}
		~SEAPLANE(){
		}
		void Show(){
				cout<<"速度为"<<speed<<endl;
						cout<<"翼展为"<<width<<endl;
		cout<<"吃水深为"<<depth<<endl;	
		}
};
int main() {
	

	return 0;
}
