#include<iostream>
using namespace std;
class BankAccout{
    protected:
    string accnum;
    double balance;
    public:
    BankAccout(string accnum,double bal=0):accnum(accnum),balance(bal){}
    virtual void Calculateinterest()=0;
    virtual void withdraw(double amount) = 0;

    void deposit(double amount){
        balance+=amount;
        cout << "Deposited " << amount << " via Cash. New balance: " << balance << endl;
    }
    void deposit(double amount,string type){
        if(type=="check"){
            balance+=amount;
            cout << "Deposited " << amount << " via Check. New balance: " << balance << endl;
        }
        else if(type=="online"){
            balance+=amount;
            cout << "Deposited " << amount << " via Online. New balance: " << balance << endl;
        }
        else cout << "Invalid deposit method!" << endl;
    }

    double operator+(const BankAccout &obj) const {  
        return this->balance + obj.balance;  
    }
    void operator-(double amount) {  
        balance -= amount;
    }
    void operator*(double interestRate) {  
        balance *= (1 + interestRate);  
    }
    double operator/(int months) {  
        if (months == 0) {
            cout << "Error: Cannot divide by zero months!" << endl;
            return 0;
        }
        return balance / months;
    }
    void displayamount(){
        cout << "Account Number: " << accnum << ", Balance: $" << balance << endl;
    }
   double getbalance(){return balance;}

};
class SavingAccount: public BankAccout{
    public:
    SavingAccount(string accnum,double bal=0):BankAccout(accnum,bal){}
    void Calculateinterest()override{
        double interest = balance * 0.05;  
        balance += interest;
        cout << "Interest added: $" << interest << ". New balance: $" << balance << endl;
    }
    void withdraw(double amount) override
    {
        if (amount>0 &&amount <=balance && balance>=500)
        {
            balance -= amount;
            cout << "Amount: " << amount << " has been withdrawn from your Savings Account." << endl;
        }
        else
        {
            cout << "Error: Insufficient balance or below minimum balance requirement." << endl;
        }
    }

};
class CurrentAccount: public BankAccout{
    public:
    CurrentAccount(string accnum,double bal=0):BankAccout(accnum,bal){}
    void  Calculateinterest()override{
        cout << "No interest for Current Account." << endl;
    }
    void withdraw(double amount) override {
        if (balance - amount < -1000) { 
            cout << "Withdrawal denied! Overdraft limit of $1000 exceeded." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: $" << balance << endl;
        }
    }

};
int main(){
    SavingAccount s1("8278937629",20000);
    CurrentAccount c1("987568922",50000);

    cout << "--- Depositing in Savings Account ---" << endl;
    s1.deposit(500);  
    s1.deposit(1000, "check");  
    s1.deposit(2000, "online");  

    cout << "\n--- Depositing in Current Account ---" << endl;
    c1.deposit(700);  
    c1.deposit(1200, "check");  
    c1.deposit(1500, "online"); 
    

    cout<<"\n---- Withdrawing amount from Savings Account ---"<<endl;
    s1.withdraw(10000);
    s1.displayamount();

    cout<<"\n---- Withdrawing amount from Current Account ---"<<endl;
    c1.withdraw(60000);
    c1.displayamount();

    cout<<"\n--- Adding Amount of both Accounts ---"<<endl;
    cout<<"New amount : "<<s1+c1<<endl;
    cout<<"\n--- Subtracting 2000 from both Accounts ---"<<endl;
    c1-2000;
    s1-2000;
    cout<<"Saving account-> New amount : "<<s1.getbalance()<<endl;
    cout<<"Current account-> New amount : "<<c1.getbalance()<<endl;
    
    cout<<"\n--- Applying Interest of 5% on both accounts ---"<<endl;
    c1*0.05;
    s1*0.05;
    cout<<"Saving account-> New amount (after interest): "<<s1.getbalance()<<endl;
    cout<<"Current account-> New amount (after interest): "<<c1.getbalance()<<endl;

    cout<<"\n--- Calculating instalments plans for 6 months "<<endl;
    double instalemnt1=c1/6;
    double instalemnt=s1/6;
    cout << "Saving account-> Equal monthly installment for 6 months: " << instalemnt<< endl;
    cout << "Current account->Equal monthly installment for 6 months: " << instalemnt1<< endl;


    return 0;
}