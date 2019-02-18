#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class BankAccount{
	string Holders_name;
	int Account_Number;
	float Balance;
	float Balance_limit;
	float* Transactions;
	int Total_trans;
	int transaction_limit;
public:
	BankAccount(string name,int Acc_Num_);
	void Print();
	void withDraw(float amount);
	void increaseTranCapacity();
	bool checkBalance(float amount);
	void set_Balance_limit(int amount);
	void deposit(float amount);
	~BankAccount();
};