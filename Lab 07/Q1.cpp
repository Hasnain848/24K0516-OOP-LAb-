#include<iostream>
using namespace std;
class Account{
    protected:
    int accountnumber;
    double balance;
    string accountname;
    public:
    Account(int accNum, double bal,string holder)
        : accountnumber(accNum), balance(bal), accountname(holder) {}//, accountType(type)
    void deposit(double amount){
        if(amount<0){
            cout<<"Invalid amount"<<endl;
            return;
        }
        balance+=amount;
         cout << "Amount: " << amount << " has been deposit to your Account" << endl;

    }
    virtual void withdraw(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount " << endl;
            return;
        }
        if (amount > balance)
        {
            cout << "Sorry Insufficient balance" << endl;
            return;
        }
        balance -= amount;
        cout << "Amount: " << amount << " has been withdraw from you Account" << endl;
    }
   virtual double Calculateinterest(){

    }
   virtual void printstatement(){
    cout<<"=======Account Statement========"<<endl;
    cout<<"Account number: "<<accountnumber<<endl;
    cout<<"Balance: "<<balance<<endl;
    }
    void getinfo(){
          cout<<"=======Account Details======="<<endl;
    cout<<"Account number: "<<accountnumber<<endl;
    cout<<"Name: "<<accountname<<endl;
    cout<<"Balance: "<<balance<<endl;
   

    }
};
class SavingsAccount : public Account{
    float interestrate;
    double minimumbalance;
    public:
    double Calculateinterest()override{
        return interestrate*balance;
    };
    void printstatement()override{
         Account::printstatement();
        cout<<"Interest rate: "<<interestrate<<endl;
        cout<<"Minimum Balance"<<minimumbalance<<endl;
        cout<<"Your interest: "<<Calculateinterest()<<endl;

    }
    void withdraw(double amount)override{
        if(amount>0 && (balance -amount)>=minimumbalance){
            balance-=amount;
        }
        else cout<<"Error"<<endl;

    }

};
class CheckingAccount : public Account{
    public:
   double Calculateinterest()override{

    };
    void printstatement()override{
       

    }


};
class FixeddepositAmount : public Account{
    string maturitydate;
    float fixedinterestrate;
    public:
    double Calculateinterest()override{
        return fixedinterestrate*balance;


    };
    void printstatement()override{
        Account::printstatement();
         cout<<"Interest rate: "<<fixedinterestrate<<endl;
        cout<<" Maturity date"<<maturitydate<<endl;
        cout<<"Your interest: "<<Calculateinterest()<<endl;

        
    }

};