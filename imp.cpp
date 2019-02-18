#include"bankAccount.h"

BankAccount::BankAccount(string name,int Acc_Num){
	Holders_name=name;
	Account_Number=Acc_Num;
	Balance=0;
	Balance_limit=200000;
	Transactions=new float[10];
	Total_trans=0;
	transaction_limit=10;
}
void BankAccount::Print(){
	cout<<"Name of account holder : "<<Holders_name<<endl;
	cout<<"Account number : "<<Account_Number<<endl;
	cout<<"Total balance : "<<Balance<<endl;
	cout<<"Total transactions : "<<Total_trans<<endl;
	cout<<"Transaction history : ";
	for(int i=0;i<Total_trans;i++){
		cout<<Transactions[i]<<" ";
	}
	cout<<endl;
}
bool BankAccount::checkBalance(float amount){
	if(amount<=Balance){
		return true;
	}
	return false;
}
void BankAccount:: increaseTranCapacity(){
	transaction_limit+=10;
	float*temp=Transactions;
	Transactions=new float[transaction_limit];
	for(int i=0;i<Total_trans;i++){
		Transactions[i]=temp[i];
	}
	delete[]temp;
}
void BankAccount::withDraw(float amount){
	if(Total_trans<transaction_limit){
		if(checkBalance(amount)){
		Balance-=amount;
		Transactions[Total_trans]=-amount;
		Total_trans++;
		cout<<"Transaction successful"<<endl;
		}
		else{
		cout<< "Transaction Unsuccessful: Insufficient balance"<<endl;
		}
	}else{
		increaseTranCapacity();
		if(checkBalance(amount)){
		Balance-=amount;
		Transactions[Total_trans]=-amount;
		Total_trans++;
		cout<<"Transaction successful"<<endl;
		}
		else{
		cout<< "Transaction Unsuccessful: Insufficient balance"<<endl;
		}
	}
}
void BankAccount::set_Balance_limit(int amount){
	Balance_limit+=amount;

}
void BankAccount::deposit(float amount){
	if(Total_trans<transaction_limit){
		if(amount+Balance <= Balance_limit){
		Balance+=amount;
		Transactions[Total_trans]=amount;
		Total_trans++;
		cout<<"Transaction successful"<<endl;
		}
		else{
		cout<< "Transaction Unsuccessful: Amount over balance limit"<<endl;
		}
	}else{
		increaseTranCapacity();
		if(amount+Balance <= Balance_limit){
		Balance+=amount;
		Transactions[Total_trans]=amount;
		Total_trans++;
		cout<<"Transaction successful"<<endl;
		}
		else{
		cout<< "Transaction Unsuccessful: Amount over balance limit"<<endl;
		}
	}
}
BankAccount::~BankAccount(){
	delete[]Transactions;
	Transactions=nullptr;
}