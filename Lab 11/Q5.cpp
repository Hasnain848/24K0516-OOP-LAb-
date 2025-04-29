#include<iostream>
using namespace std;
class  InsufficientFundsException : public exception{
    public:
    const char* what() const noexcept override{
        return("InsufficientFundsException -");
    }
};
template <typename T>
class BankAccount{
 T balance;
 public:
 BankAccount(T bal):balance(bal){}
 void withdraw(T amount){
    if(amount>balance)throw InsufficientFundsException();
    balance -= amount;
 }
 T getbalance(){return balance;}
};
int main(){
    BankAccount acc (600);
    double amount;
    try {
        cout<<"Enter the Amount to withdraw: ";
        cin>>amount;
        acc.withdraw(amount);
        cout<<"Amount withdrawed"<<endl;
    }
    catch(const InsufficientFundsException & e){
        cout<<e.what()<<"Denied :$"<<amount - acc.getbalance()<<endl;
    }
}