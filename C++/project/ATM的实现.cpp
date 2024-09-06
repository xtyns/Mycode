#include "Account.h"
#include <fstream>

void initDepo(DepositAccount &de, string str[4], int bal) { //初始化存款账户
	de.setAccount(str[0]);
	de.setName(str[1]);
	de.setId(str[2]);
	de.setPassword(str[3]);
	de.setBal(bal);
}

void initLoan(LoanAccount &lo, string str[], int cre, int debt) { //初始化借款账户
	lo.setAccount(str[0]);
	lo.setName(str[1]);
	lo.setId(str[2]);
	lo.setPassword(str[3]);
	lo.setCredit(cre);
	lo.setDebt(debt);
}

void printDepo(DepositAccount de) {
	cout << de.getAccount() << " ";
	cout << de.getName() << " ";
	cout << de.getId() << " ";
	cout << de.getPassword() << " ";
	cout << de.getBal() << endl;
}

void printLoan(LoanAccount lo) {
	cout << lo.getAccount() << " ";
	cout << lo.getName() << " ";
	cout << lo.getId() << " ";
	cout << lo.getPassword() << " ";
	cout << lo.getCredit() << " ";
	cout << lo.getDebt() << endl;
}

int main() {
	system("cls"); // 清屏 
	ifstream ifs;
	ifs.open("account.in", ios::in);
	string str[4];
	int bal, cre, debt;
	for (int i = 0; i < 4; i++)
		ifs >> str[i];
	ifs >> bal;
	initDepo(depo, str, bal);

	for (int i = 0; i < 4; i++)
		ifs >> str[i];
	ifs >> cre >> debt;
	initLoan(loan, str, cre, debt);

	ifs.close();

	depo.getCard();
	cout << endl;
	loan.getCard();

	freopen("account.in", "w", stdout);
	printDepo(depo);
	printLoan(loan);
	return 0;
}
