#include <iostream>
using namespace std;

class Accounts
{
    string accountnumber;
    string accountholder;
    double balance;

public:
    Accounts(string number = "0", string holder = "", double bal = 0)
        : accountnumber(number), accountholder(holder), balance(bal) {}
    void deposit(double amount)
    {
        if (amount < 0)
        {
            cout << "Enter correct amount" << endl;
            return;
        }
        balance += amount;
        cout << "Amount: " << amount << " has been added" << endl;
    }
    void withdraw(double amount)
    {
        if (amount < 0 || amount > balance)
        {
            cout << "Error in transaction" << endl;
            return;
        }
        balance -= amount;
        cout << "Amount: " << amount << " has been withdrawn" << endl;
    }
    Accounts operator+(const Accounts &obj) const
    {
        return Accounts(accountnumber, accountholder, balance + obj.balance);
    }
    Accounts &operator-=(double amount)
    {
        balance -= amount;
        return *this;
    }
    bool operator>(const Accounts &obj)
    {
        return balance > obj.balance;
    }
    double getbalance() { return balance; }
    string getname() { return accountholder; }
    friend ostream &operator<<(ostream &out, const Accounts &obj);
};
ostream &operator<<(ostream &out, const Accounts &obj)
{
    out << "====== Account Details ======" << endl;
    out << "Account number: " << obj.accountnumber << endl;
    out << "Account Holder: " << obj.accountholder << endl;
    out << "Balance: " << obj.balance << endl;
    return out;
}

int main()
{
    Accounts acc1("095547289", "Hasnain", 50000);
    Accounts acc2("652788392", "Yousha", 90000);

    cout << acc1 << endl;
    cout << acc2 << endl;
    cout << "--------------------------------------------------------------------" << endl;
    Accounts acc3 = acc1 + acc2;
    cout << "Total Balance (After Addition): " << acc3.getbalance() << endl; // Fixed endl
    cout << "--------------------------------------------------------------------" << endl;

    acc2 -= 2000;
    cout << "After transfer  2000 from " << acc2.getname() << "'s account" << endl;
    cout << "New Balance: " << acc2.getbalance() << endl;

    cout << "--------------------------------------------------------------------" << endl;
    cout << "Comparison" << endl;
    if (acc1 > acc2)
    {
        cout << acc1.getname() << " has a higher balance than " << acc2.getname() << endl;
    }
    else
    {
        cout << acc2.getname() << " has a higher balance than " << acc1.getname() << endl;
    }

    cout << "--------------------------------------------------------------------" << endl;
    cout << acc1 << endl;
    cout << acc2 << endl;

    return 0;
}
