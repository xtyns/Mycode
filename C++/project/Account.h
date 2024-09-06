#ifndef Atmprogram
#define Atmprogram

#include <iostream>
#include <string>
using namespace std;

class Account {
	private:
		string userAccount;  //用户账号
		string userName;     //用户姓名
		string idCard;       //用户身份证
		string userPassword; //用户密码

	public:
		Account(string account, string name, string id, string pwd) {
			userAccount = account;
			userName = name;
			idCard = id;
			userPassword = pwd;
		}

		void setAccount(string account) {
			userAccount = account;
		}

		void setName(string name) {
			userName = name;
		}

		void setId(string id) {
			idCard = id;
		}

		void setPassword(string pwd) {
			userPassword = pwd;
		}

		string getAccount() {
			return userAccount;
		}

		string getName() {
			return userName;
		}

		string getId() {
			return idCard;
		}

		string getPassword() {
			return userPassword;
		}

		void getCard() { //插卡交互界面
			cout << "---------------------正在启动自助取款机---------------------" << endl;
			cout << "请插入您的银行卡" << endl;
			cout << "已识别账户：" << getAccount() << endl;
			cout << "插入成功！" << endl;
			system("pause");
			system("cls");
			cout << "----------------------欢迎来到中国银行----------------------" << endl;
			cout << "已识别账户：" << getAccount() << endl;
			cout << "请输入你的密码(温馨提示:输入错误3次即被锁卡):";
			string password;
			for (int i = 0; i < 3; i++) {
				cin >> password;
				if (password == getPassword()) {
					cout << "恭喜您登陆成功" << endl;
					system("pause");
					system("cls");
					operate();
					break;
				} else if (i == 2)
					cout << "您已经输错密码三次，系统自动锁卡，请于次日凭身份证领卡" << endl;
				else
					cout << "您的密码有误，请重新输入(您还有" << 2 - i << "次重输机会):";
			}
			cout << "----------------------期待下次为您服务----------------------" << endl;
			system("pause");
			system("cls");
		}

		void changePassword() { //修改密码
			string pwd1, pwd2;
			cout << "请输入新的密码:";
			while (true) {
				cin >> pwd1;
				if (pwd1 == getPassword())
					cout << "新密码不能与旧密码相同，请重新输入新的密码:";
				else
					break;
			}

			cout << "请确认新的密码:";
			cin >> pwd2;
			if (pwd1 == pwd2) {
				setPassword(pwd1);
				cout << "密码修改成功\n"
				     << endl;
			} else
				cout << "前后密码不一致，修改失败\n"
				     << endl;
		}

		virtual void operate() {};
		virtual void withdraw() {};
};

class LoanAccount : public Account { //借款账户
	private:
		int credit; //信用额度
		int debt;   //当前欠款
	public:
		LoanAccount(string account, string name, string id, string pwd, int cre, int dt) : Account(account, name, id, pwd) {
			credit = cre;
			debt = dt;
		}

		int getCredit() {
			return credit;
		}

		int getDebt() {
			return debt;
		}

		void setCredit(int cre) {
			credit = cre;
		}

		void setDebt(int dt) {
			debt = dt;
		}

		void operate() {
			cout << "此账户为借款账户,以下为您的基本信息" << endl;
			cout << "-------------------------------------" << endl;
			cout << "账号   " << getAccount() << endl;
			cout << "姓名   " << getName() << endl;
			cout << "身份证  " << getId() << endl;
			cout << "密码   " << getPassword() << endl;
			cout << "信用额度  " << getCredit() << endl;
			cout << "当前欠款  " << getDebt() << endl;
			cout << "-------------------------------------" << endl;
			system("pause");
			system("cls");
			int num;
			while (true) {
				cout << "此账户为借款账户,以下为您的基本信息" << endl;
				cout << "-------------------------------------" << endl;
				cout << "账号   " << getAccount() << endl;
				cout << "姓名   " << getName() << endl;
				cout << "身份证  " << getId() << endl;
				cout << "-------------------------------------" << endl;
				cout << "----------------------本机提供以下服务----------------------" << endl;
				cout << "1.还款  2.取款  3.查询欠款  4.查询信用额度  5.修改密码  6.退卡" << endl;
				cout << "请根据提示栏输入对应数字进入相应服务:";
				cin >> num;
				switch (num) {
					case 1:
						repayment();
						break;
					case 2:
						withdraw();
						break;
					case 3:
						checkDebt();
						break;
					case 4:
						checkCredit();
						break;
					case 5:
						changePassword();
						break;
					case 6:
						cout << "您已经退卡" << endl;
						return;
					default:
						cout << "无效的输入，执行退卡" << endl;
						return;
				}
				system("pause");
				system("cls");
			}
		}

		void repayment() { //还款
			if (getDebt() == 0)
				cout << "您欠款已经还清，无需还款" << endl;
			else {
				cout << "您目前待还" << getDebt() << "元" << endl;
				int money;
				cout << "请将您的存款整理好放入ATM机中并输入还款金额:";
				cin >> money;
				cout << "系统正在处理中..." << endl;
				setDebt(getDebt() - money);
				if (getDebt() == 0)
					cout << "您本次还款" << money << "元，欠款已经还清，即将返回主界面...\n"
					     << endl;
				else
					cout << "您本次还款" << money << "元，还有" << getDebt() << "元待还，即将返回主界面...\n"
					     << endl;
			}
		}

		void repayment(int money) { //转账还款
			setDebt(getDebt() - money);
		}

		void withdraw() { //取款
			int remain = getCredit() - getDebt();
			if (remain < 100)
				cout << "您的额度不足，无法进行取款" << endl;
			else {
				cout << "请输入取款金额:";
				int money;
				static int withdraw2 = 0;
				while (true) {
					cin >> money;
					if (money % 100 == 0) {
						if (remain - money < 0) {
							cout << "您的余额不足，当前还可取" << remain << "元，请重新输入取款金额:";
						} else if (money > 5000) {
							cout << "单笔取款最大限额为5000元，请重新输入取款金额:";
						} else {
							if (withdraw2 + money > 14000) {
								cout << "单日最大取款金额为14000元，您今日还可以取" << 14000 - withdraw2 << "元，请重新输入取款金额:";
							} else {
								cout << "请稍等，系统正在处理中..." << endl;
								setDebt(getDebt() + money);
								withdraw2 += money;
								cout << "取款成功，即将返回主界面...\n"
								     << endl;
								return;
							}
						}
					} else
						cout << "每次取款额为100的整数倍，请重新输入取款金额:";
				}
			}
		}

		void checkDebt() { //查询欠款
			if (getDebt() == 0)
				cout << "您的欠款已经还清" << endl;
			else {
				cout << "您当前欠款:" << getDebt() << "元" << endl;
				cout << "即将返回主界面...\n"
				     << endl;
			}
		}

		void checkCredit() { //查询信用额度
			cout << "您当前的信用额度为:" << getCredit() << "元" << endl;
			cout << "即将返回主界面...\n"
			     << endl;
		}
};

LoanAccount loan("", "", "", "", 0, 0); //实例化一个借款账户，因为需要在存款账户的转账中用到

class DepositAccount : public Account { //存款账户
	private:
		int balance; //用户余额
	public:
		DepositAccount(string account, string name, string id, string pwd, int bal) : Account(account, name, id, pwd) {
			balance = bal;
		}

		int getBal() {
			return balance;
		}

		void setBal(int bal) {
			balance = bal;
		}

		void operate() {
			cout << "此账户为存款账户,以下为您的基本信息" << endl;
			cout << "-------------------------------------" << endl;
			cout << "账号   " << getAccount() << endl;
			cout << "姓名   " << getName() << endl;
			cout << "身份证  " << getId() << endl;
			cout << "密码   " << getPassword() << endl;
			cout << "余额  " << getBal() << endl;
			cout << "-------------------------------------" << endl;
			system("pause");
			system("cls");
			int num;
			while (true) {
		
				cout << "此账户为存款账户,以下为您的基本信息" << endl;
				cout << "-------------------------------------" << endl;
				cout << "账号   " << getAccount() << endl;
				cout << "姓名   " << getName() << endl;
				cout << "身份证  " << getId() << endl;
				cout << "-------------------------------------" << endl;

				cout << "----------------------本机提供以下服务----------------------" << endl;
				cout << "1.存款   2.取款   3.转账   4.查询余额   5.修改密码   6.退卡" << endl;
				cout << "请根据提示栏输入对应数字进入相应服务:";
				cin >> num;
				switch (num) {
					case 1:
						deposit();
						break;
					case 2:
						withdraw();
						break;
					case 3:
						transfer();
						break;
					case 4:
						checkBalances();
						break;
					case 5:
						changePassword();
						break;
					case 6:
						cout << "您已经退卡" << endl;
						return;
					default:
						cout << "无效的输入，执行退卡" << endl;
						return;

				}
				system("pause");
				system("cls");

			}
		}

		void deposit() { //存款
			int money;
			cout << "请将您的存款整理好放入ATM机中并输入存款金额:" << endl;
			cin >> money;
			cout << "系统正在处理中..." << endl;
			setBal(getBal() + money);
			cout << "存款成功，即将返回主界面...\n"
			     << endl;

		}

		void withdraw() { //取款
			if (getBal() < 100)
				cout << "您的余额不足，无法进行取款" << endl;
			else {
				cout << "请输入取款金额:";
				int money;
				static int withdraw1 = 0;
				while (true) {
					cin >> money;
					if (money % 100 == 0) {
						if (getBal() - money < 0) {
							cout << "您的余额不足，请重新输入取款金额:";
						} else if (money > 1000) {
							cout << "单笔取款最大限额为1000元，请重新输入取款金额:";
						} else {
							if (withdraw1 + money > 5000) {
								cout << "单日最大取款金额为5000元，您今日还可以取" << 5000 - withdraw1 << "元，请重新输入取款金额:";
							} else {
								cout << "请稍等，系统正在处理中..." << endl;
								setBal(getBal() - money);
								withdraw1 += money;
								cout << "取款成功，即将返回主界面...\n"
								     << endl;
								return;
							}
						}
					} else
						cout << "每次取款额为100的整数倍，请重新输入取款金额:";
				}
			}
		}

		void transfer() { //转账
			while (true) {
				string account1, account2;
				cout << "请输入转入账户账号:";
				cin >> account1;
				cout << "请确认转入账户账号:";
				cin >> account2;
				if (account1 == account2) {
					cout << "请耐心等待系统确认..." << endl;
					cout << "确认完毕，请输入转账金额(取消转账请输入0):";
					int money;
					while (true) {
						cin >> money;
						if (money == 0) {
							cout << "请稍等，系统正在取消转账..." << endl;
							cout << "成功取消转账，即将返回主界面...\n"
							     << endl;
							return;
						} else if (money > getBal()) {
							cout << "您的转账金额超出了您的余额!" << endl;
							cout << "若您想继续转账，请重新输入金额(取消转账请输入0):";
						} else if (loan.getAccount() == account1) {
							cout << "系统正在处理中..." << endl;
							if (money > loan.getDebt()) {
								cout << "你所转账的借款账户只欠了" << loan.getDebt() << "元" << endl;
								cout << "如果您同意只转账" << loan.getDebt() << "元请按1,按0重新输入金额:";
								int flag;
								cin >> flag;
								if (flag == 1) {
									money = loan.getDebt();
									loan.repayment(money);
									setBal(getBal() - money);
									cout << "转账成功，即将返回主界面...\n"
									     << endl;
									return;
								} else {
									cout << "请重新输入金额(取消转账请输入0):" << endl;
								}
							} else {
								loan.repayment(money);
								setBal(getBal() - money);
								cout << "转账成功，即将返回主界面...\n"
								     << endl;
								return;
							}
						} else {
							cout << "系统正在处理中..." << endl;
							setBal(getBal() - money);
							cout << "转账成功，即将返回主界面...\n"
							     << endl;
							return;
						}
					}
					break;
				} else
					cout << "两次账号输入不一致，请重新输入" << endl;
			}
		}

		void checkBalances() { //查询余额
			cout << "您的余额为:" << getBal() << "元" << endl;
			cout << "即将返回主界面...\n"
			     << endl;
		}
};

DepositAccount depo("", "", "", "", 0); //反正已经实例化了一个借款账户，顺便把存款账户也实例化了

#endif