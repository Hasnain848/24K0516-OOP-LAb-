/*Task 04
Problem: An e-commerce platform aims to support multiple payment methods (credit
cards, digital wallets) to attract global customers. The payment system must validate
transactions securely and allow new payment options (e.g., cryptocurrency) to be added
without rewriting existing code.
Classes and Structure:
• Abstract Class PaymentMethod:
o Member Function:
▪ processPayment(double amount): Pure virtual function to handle
transactions.
• Derived Class CreditCard:
o Data Members:
▪ cardNumber (string): Stores the card number.
o Implements processPayment() to validate and process payments.
• Derived Class DigitalWallet:
o Data Members:
▪ balance (double): Tracks available funds.
o Implements processPayment() to deduct balance.

Flow:
• Create CreditCard and DigitalWallet objects.
• Simulate payments and check for success/failure.*/
#include <iostream>
using namespace std;
class PaymentMethod
{
public:
    virtual void processPayment(double amount) = 0;
};
class CreditCard : public PaymentMethod
{
    string cardnumber;

public:
    CreditCard(string no = "") : cardnumber(no) {}
    void processPayment(double amount) override
    {
        if (cardnumber.length() != 16)
        {
            cout << "Incorrect card number " << endl;
            cout << "Payment failed" << endl;
            return;
        }
        cout << "Processing amount : " << amount << " form card no: " << cardnumber << endl;
        cout << "Payment success" << endl;
    }
};
class DigitalWallet : public PaymentMethod
{
    double balance;

public:
    DigitalWallet(double balance = 0) : balance(balance) {}
    void processPayment(double amount) override
    {
        if (amount > balance)
        {
            cout << "Transaction failed: Insufficient balance" << endl;
            cout << "Payment failed" << endl;
            return;
        }
        balance -= amount;
        cout << "Proccessing amount : " << amount << " from you walllet , New balance: " << balance << endl;
        cout << "Payment Success" << endl;
    }
};
int main()
{
    CreditCard c("1234567891234567");
    DigitalWallet d(5000);

    cout << "--- Credit Card Payment ---\n";
    c.processPayment(2000);

    cout << "\n--- Wallet Payment ---\n";
    d.processPayment(3000);

    cout << "\n--- Failed Wallet Payment (Insufficient Funds) ---\n";
    d.processPayment(3000);
    return 0;
}