#include <iostream>
using namespace std;
class BankAcount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAcount(int acc, string name, double bal) : accountNumber(acc), accountHolderName(name), balance(bal) {}
    void deposit(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount " << endl;
            return;
        }
        balance += amount;
        cout << "Amount: " << amount << " has been deposit to your Account" << endl;
    }
    void withdraw(double amount)
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
    void display()
    {
        cout << "============Acouint Details============" << endl;
        cout << "Account no: " << accountNumber << endl;
        cout << "Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "=======================================" << endl;
    }
};
int main()
{
    BankAcount accounts[3]{
        BankAcount(101, "Hasnain", 300000),
        BankAcount(102, "Hamza", 200000),
        BankAcount(103, "Huzaifa", 500000)};
    for (int i = 0; i < 3; i++)
    {
        accounts[i].display();
    }
    accounts[0].deposit(2000);
    accounts[1].withdraw(3000);
    accounts[2].deposit(500);
    accounts[2].withdraw(8000);
    for (int i = 0; i < 3; i++)
    {
        accounts[i].display();
    }
    return 0;
}