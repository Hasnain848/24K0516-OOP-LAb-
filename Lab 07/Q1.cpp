#include <iostream>
using namespace std;

class Account
{
protected:
    int accountnumber;
    double balance;
    string accountname;
    string Accounttype;

public:
    Account(int accNum, double bal, string holder, string acctype)
        : accountnumber(accNum), balance(bal), accountname(holder), Accounttype(acctype) {}

    void deposit(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }
        balance += amount;
        cout << "Amount: " << amount << " has been deposited into your account." << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount." << endl;
            return;
        }
        if (amount > balance)
        {
            cout << "Sorry, insufficient balance." << endl;
            return;
        }
        balance -= amount;
        cout << "Amount: " << amount << " has been withdrawn from your account." << endl;
    }

    virtual double Calculateinterest() = 0;

    virtual void printstatement()
    {
        cout << "========== Account Statement ==========" << endl;
        cout << "Account number: " << accountnumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void getinfo()
    {
        cout << "========== Account Details ==========" << endl;
        cout << "Account number: " << accountnumber << endl;
        cout << "Name: " << accountname << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account type: " << Accounttype << endl;
    }
};

class SavingsAccount : public Account
{
    float interestrate;
    double minimumbalance;

public:
    SavingsAccount(int accNum, double bal, string holder, string acctype = "Saving", float rate = 2.0, double minbal = 2000)
        : Account(accNum, bal, holder, acctype), interestrate(rate), minimumbalance(minbal) {}

    double Calculateinterest() override
    {
        return (balance * interestrate) / 100;
    }

    void printstatement() override
    {
        cout << "======= Savings Account Statement =======" << endl;
        Account::printstatement();
        cout << "Interest rate: " << interestrate << "%" << endl;
        cout << "Minimum Balance: " << minimumbalance << endl;
        cout << "Your interest: " << Calculateinterest() << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > 0 && (balance - amount) >= minimumbalance)
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

class CheckingAccount : public Account
{
public:
    CheckingAccount(int accNum, double bal, string holder, string acctype = "Checking Account")
        : Account(accNum, bal, holder, acctype) {}

    double Calculateinterest() override { return 0; }

    void printstatement() override
    {
        cout << "======= Checking Account Statement =======" << endl;
        Account::printstatement();
    }
};

class FixeddepositAmount : public Account
{
    string maturitydate;
    float fixedinterestrate;

public:
    FixeddepositAmount(int accNum, double bal, string holder, string acctype = "Fixed Deposit", string maturitydate = "", float fixrate = 3.0)
        : Account(accNum, bal, holder, acctype), maturitydate(maturitydate), fixedinterestrate(fixrate) {}

    double Calculateinterest() override
    {
        return (fixedinterestrate * balance) / 100;
    }

    void printstatement() override
    {
        cout << "======= Fixed Deposit Account Statement =======" << endl;
        Account::printstatement();
        cout << "Interest rate: " << fixedinterestrate << "%" << endl;
        cout << "Maturity date: " << maturitydate << endl;
        cout << "Your interest: " << Calculateinterest() << endl;
    }

    void withdraw(double amount)
    {
        cout << "Withdrawal not allowed before maturity date." << endl;
    }
};

int main()
{
    Account *a = new SavingsAccount(1234, 60000, "Hasnain", "Saving", 2.0, 2000);
    a->getinfo();
    a->deposit(3000);
    a->withdraw(20000);
    a->printstatement();
    delete a;
    cout << endl;

    CheckingAccount obj(4321, 20000, "Yousha", "Checking");
    obj.getinfo();
    obj.deposit(3000);
    obj.withdraw(4000);
    obj.printstatement();
    cout << endl;

    FixeddepositAmount obj1(4321, 10000, "Obaid", "Fixed Deposit", "17-03-2025", 3.0);
    obj1.getinfo();
    obj1.deposit(4000);
    obj1.withdraw(5000);
    obj1.printstatement();
}
