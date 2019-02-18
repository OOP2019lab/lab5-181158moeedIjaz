#include"bankAccount.h"


int main(){
	BankAccount myAccount("John Doe",549002);
	myAccount.withDraw(2000);
	myAccount.deposit(250000);
	myAccount.deposit(2000);
	myAccount.Print();
	system("pause");
	return 0;
}
