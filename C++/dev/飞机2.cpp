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
		cout<<"�ٶ�Ϊ"<<speed<<endl;
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
		cout<<"�ٶ�Ϊ"<<speed<<endl;
		cout<<"��չΪ"<<width<<endl;
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
		cout<<"�ٶ�Ϊ"<<speed<<endl;
		cout<<"��ˮ��Ϊ"<<depth<<endl;
	}
};
class SEAPLANE:virtual public PLANE,virtual public SHIP{
	public:
		SEAPLANE(double v=0,double w,double d):speed(v),width(w),speed(v){
		}
		~SEAPLANE(){
		}
		void Show(){
				cout<<"�ٶ�Ϊ"<<speed<<endl;
						cout<<"��չΪ"<<width<<endl;
		cout<<"��ˮ��Ϊ"<<depth<<endl;	
		}
};
int main() {
	

	return 0;
}
