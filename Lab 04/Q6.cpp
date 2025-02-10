#include<iostream>
using namespace std;
class Account{
    private:
    string accountNumber;
    string accountHolderName;
    double balance;
    public:
    Account(){
        balance=0.0;
    }
    Account(string accountNumber,string accountHolderName,double balance){
        this->accountNumber=accountNumber;
        this->accountHolderName=accountHolderName;
        this->balance=balance;
    }
    void deposit(double amount){
        if(amount <0){
            cout<<"Invalid money"<<endl;
            return;
        }
        balance+=amount;
        cout<<"\n"<<amount<<" is Deposit successfull"<<endl;
    }
    void withdraw(double amount){
        if(amount>balance){
            cout<<"Insufficient Balance"<<endl;
            return;
        }
        balance-=amount;
        cout<<"Withdraw succesfully"<<endl;
    }
    void CheckBalance(){
        cout<<endl;
        cout<<"Account Name: "<<accountHolderName<<endl;
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Balance: "<<balance<<endl ;
        cout<<endl; 
    }

};
int main(){
    Account a1;
    Account a2("123456543","Hasnain",60000);
    Account a3("98765432","Obaid",100000);
    cout<<"Account no 1"<<endl;
    a1.CheckBalance();
    cout<<"-------------------------"<<endl;
    a2.CheckBalance();
    a2.deposit(40000);
    a2.CheckBalance();
    cout<<"--------------------------"<<endl;
    a3.CheckBalance();
    a3.withdraw(60000);
    a3.withdraw(60000);
    a3.CheckBalance();
    

}