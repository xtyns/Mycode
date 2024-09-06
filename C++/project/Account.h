#ifndef Atmprogram
#define Atmprogram

#include <iostream>
#include <string>
using namespace std;

class Account {
	private:
		string userAccount;  //�û��˺�
		string userName;     //�û�����
		string idCard;       //�û����֤
		string userPassword; //�û�����

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

		void getCard() { //�忨��������
			cout << "---------------------������������ȡ���---------------------" << endl;
			cout << "������������п�" << endl;
			cout << "��ʶ���˻���" << getAccount() << endl;
			cout << "����ɹ���" << endl;
			system("pause");
			system("cls");
			cout << "----------------------��ӭ�����й�����----------------------" << endl;
			cout << "��ʶ���˻���" << getAccount() << endl;
			cout << "�������������(��ܰ��ʾ:�������3�μ�������):";
			string password;
			for (int i = 0; i < 3; i++) {
				cin >> password;
				if (password == getPassword()) {
					cout << "��ϲ����½�ɹ�" << endl;
					system("pause");
					system("cls");
					operate();
					break;
				} else if (i == 2)
					cout << "���Ѿ�����������Σ�ϵͳ�Զ����������ڴ���ƾ���֤�쿨" << endl;
				else
					cout << "����������������������(������" << 2 - i << "���������):";
			}
			cout << "----------------------�ڴ��´�Ϊ������----------------------" << endl;
			system("pause");
			system("cls");
		}

		void changePassword() { //�޸�����
			string pwd1, pwd2;
			cout << "�������µ�����:";
			while (true) {
				cin >> pwd1;
				if (pwd1 == getPassword())
					cout << "�����벻�����������ͬ�������������µ�����:";
				else
					break;
			}

			cout << "��ȷ���µ�����:";
			cin >> pwd2;
			if (pwd1 == pwd2) {
				setPassword(pwd1);
				cout << "�����޸ĳɹ�\n"
				     << endl;
			} else
				cout << "ǰ�����벻һ�£��޸�ʧ��\n"
				     << endl;
		}

		virtual void operate() {};
		virtual void withdraw() {};
};

class LoanAccount : public Account { //����˻�
	private:
		int credit; //���ö��
		int debt;   //��ǰǷ��
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
			cout << "���˻�Ϊ����˻�,����Ϊ���Ļ�����Ϣ" << endl;
			cout << "-------------------------------------" << endl;
			cout << "�˺�   " << getAccount() << endl;
			cout << "����   " << getName() << endl;
			cout << "���֤  " << getId() << endl;
			cout << "����   " << getPassword() << endl;
			cout << "���ö��  " << getCredit() << endl;
			cout << "��ǰǷ��  " << getDebt() << endl;
			cout << "-------------------------------------" << endl;
			system("pause");
			system("cls");
			int num;
			while (true) {
				cout << "���˻�Ϊ����˻�,����Ϊ���Ļ�����Ϣ" << endl;
				cout << "-------------------------------------" << endl;
				cout << "�˺�   " << getAccount() << endl;
				cout << "����   " << getName() << endl;
				cout << "���֤  " << getId() << endl;
				cout << "-------------------------------------" << endl;
				cout << "----------------------�����ṩ���·���----------------------" << endl;
				cout << "1.����  2.ȡ��  3.��ѯǷ��  4.��ѯ���ö��  5.�޸�����  6.�˿�" << endl;
				cout << "�������ʾ�������Ӧ���ֽ�����Ӧ����:";
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
						cout << "���Ѿ��˿�" << endl;
						return;
					default:
						cout << "��Ч�����룬ִ���˿�" << endl;
						return;
				}
				system("pause");
				system("cls");
			}
		}

		void repayment() { //����
			if (getDebt() == 0)
				cout << "��Ƿ���Ѿ����壬���軹��" << endl;
			else {
				cout << "��Ŀǰ����" << getDebt() << "Ԫ" << endl;
				int money;
				cout << "�뽫���Ĵ������÷���ATM���в����뻹����:";
				cin >> money;
				cout << "ϵͳ���ڴ�����..." << endl;
				setDebt(getDebt() - money);
				if (getDebt() == 0)
					cout << "�����λ���" << money << "Ԫ��Ƿ���Ѿ����壬��������������...\n"
					     << endl;
				else
					cout << "�����λ���" << money << "Ԫ������" << getDebt() << "Ԫ��������������������...\n"
					     << endl;
			}
		}

		void repayment(int money) { //ת�˻���
			setDebt(getDebt() - money);
		}

		void withdraw() { //ȡ��
			int remain = getCredit() - getDebt();
			if (remain < 100)
				cout << "���Ķ�Ȳ��㣬�޷�����ȡ��" << endl;
			else {
				cout << "������ȡ����:";
				int money;
				static int withdraw2 = 0;
				while (true) {
					cin >> money;
					if (money % 100 == 0) {
						if (remain - money < 0) {
							cout << "�������㣬��ǰ����ȡ" << remain << "Ԫ������������ȡ����:";
						} else if (money > 5000) {
							cout << "����ȡ������޶�Ϊ5000Ԫ������������ȡ����:";
						} else {
							if (withdraw2 + money > 14000) {
								cout << "�������ȡ����Ϊ14000Ԫ�������ջ�����ȡ" << 14000 - withdraw2 << "Ԫ������������ȡ����:";
							} else {
								cout << "���Եȣ�ϵͳ���ڴ�����..." << endl;
								setDebt(getDebt() + money);
								withdraw2 += money;
								cout << "ȡ��ɹ�����������������...\n"
								     << endl;
								return;
							}
						}
					} else
						cout << "ÿ��ȡ���Ϊ100��������������������ȡ����:";
				}
			}
		}

		void checkDebt() { //��ѯǷ��
			if (getDebt() == 0)
				cout << "����Ƿ���Ѿ�����" << endl;
			else {
				cout << "����ǰǷ��:" << getDebt() << "Ԫ" << endl;
				cout << "��������������...\n"
				     << endl;
			}
		}

		void checkCredit() { //��ѯ���ö��
			cout << "����ǰ�����ö��Ϊ:" << getCredit() << "Ԫ" << endl;
			cout << "��������������...\n"
			     << endl;
		}
};

LoanAccount loan("", "", "", "", 0, 0); //ʵ����һ������˻�����Ϊ��Ҫ�ڴ���˻���ת�����õ�

class DepositAccount : public Account { //����˻�
	private:
		int balance; //�û����
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
			cout << "���˻�Ϊ����˻�,����Ϊ���Ļ�����Ϣ" << endl;
			cout << "-------------------------------------" << endl;
			cout << "�˺�   " << getAccount() << endl;
			cout << "����   " << getName() << endl;
			cout << "���֤  " << getId() << endl;
			cout << "����   " << getPassword() << endl;
			cout << "���  " << getBal() << endl;
			cout << "-------------------------------------" << endl;
			system("pause");
			system("cls");
			int num;
			while (true) {
		
				cout << "���˻�Ϊ����˻�,����Ϊ���Ļ�����Ϣ" << endl;
				cout << "-------------------------------------" << endl;
				cout << "�˺�   " << getAccount() << endl;
				cout << "����   " << getName() << endl;
				cout << "���֤  " << getId() << endl;
				cout << "-------------------------------------" << endl;

				cout << "----------------------�����ṩ���·���----------------------" << endl;
				cout << "1.���   2.ȡ��   3.ת��   4.��ѯ���   5.�޸�����   6.�˿�" << endl;
				cout << "�������ʾ�������Ӧ���ֽ�����Ӧ����:";
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
						cout << "���Ѿ��˿�" << endl;
						return;
					default:
						cout << "��Ч�����룬ִ���˿�" << endl;
						return;

				}
				system("pause");
				system("cls");

			}
		}

		void deposit() { //���
			int money;
			cout << "�뽫���Ĵ������÷���ATM���в���������:" << endl;
			cin >> money;
			cout << "ϵͳ���ڴ�����..." << endl;
			setBal(getBal() + money);
			cout << "���ɹ�����������������...\n"
			     << endl;

		}

		void withdraw() { //ȡ��
			if (getBal() < 100)
				cout << "�������㣬�޷�����ȡ��" << endl;
			else {
				cout << "������ȡ����:";
				int money;
				static int withdraw1 = 0;
				while (true) {
					cin >> money;
					if (money % 100 == 0) {
						if (getBal() - money < 0) {
							cout << "�������㣬����������ȡ����:";
						} else if (money > 1000) {
							cout << "����ȡ������޶�Ϊ1000Ԫ������������ȡ����:";
						} else {
							if (withdraw1 + money > 5000) {
								cout << "�������ȡ����Ϊ5000Ԫ�������ջ�����ȡ" << 5000 - withdraw1 << "Ԫ������������ȡ����:";
							} else {
								cout << "���Եȣ�ϵͳ���ڴ�����..." << endl;
								setBal(getBal() - money);
								withdraw1 += money;
								cout << "ȡ��ɹ�����������������...\n"
								     << endl;
								return;
							}
						}
					} else
						cout << "ÿ��ȡ���Ϊ100��������������������ȡ����:";
				}
			}
		}

		void transfer() { //ת��
			while (true) {
				string account1, account2;
				cout << "������ת���˻��˺�:";
				cin >> account1;
				cout << "��ȷ��ת���˻��˺�:";
				cin >> account2;
				if (account1 == account2) {
					cout << "�����ĵȴ�ϵͳȷ��..." << endl;
					cout << "ȷ����ϣ�������ת�˽��(ȡ��ת��������0):";
					int money;
					while (true) {
						cin >> money;
						if (money == 0) {
							cout << "���Եȣ�ϵͳ����ȡ��ת��..." << endl;
							cout << "�ɹ�ȡ��ת�ˣ���������������...\n"
							     << endl;
							return;
						} else if (money > getBal()) {
							cout << "����ת�˽������������!" << endl;
							cout << "���������ת�ˣ�������������(ȡ��ת��������0):";
						} else if (loan.getAccount() == account1) {
							cout << "ϵͳ���ڴ�����..." << endl;
							if (money > loan.getDebt()) {
								cout << "����ת�˵Ľ���˻�ֻǷ��" << loan.getDebt() << "Ԫ" << endl;
								cout << "�����ͬ��ֻת��" << loan.getDebt() << "Ԫ�밴1,��0����������:";
								int flag;
								cin >> flag;
								if (flag == 1) {
									money = loan.getDebt();
									loan.repayment(money);
									setBal(getBal() - money);
									cout << "ת�˳ɹ�����������������...\n"
									     << endl;
									return;
								} else {
									cout << "������������(ȡ��ת��������0):" << endl;
								}
							} else {
								loan.repayment(money);
								setBal(getBal() - money);
								cout << "ת�˳ɹ�����������������...\n"
								     << endl;
								return;
							}
						} else {
							cout << "ϵͳ���ڴ�����..." << endl;
							setBal(getBal() - money);
							cout << "ת�˳ɹ�����������������...\n"
							     << endl;
							return;
						}
					}
					break;
				} else
					cout << "�����˺����벻һ�£�����������" << endl;
			}
		}

		void checkBalances() { //��ѯ���
			cout << "�������Ϊ:" << getBal() << "Ԫ" << endl;
			cout << "��������������...\n"
			     << endl;
		}
};

DepositAccount depo("", "", "", "", 0); //�����Ѿ�ʵ������һ������˻���˳��Ѵ���˻�Ҳʵ������

#endif