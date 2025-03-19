#include <iostream>
using namespace std;

class Currency {
public:
    double amount;
    string currencycode;
    string currencysymbol;
    double exchangerate;

public:
    Currency(double amount, string code, string symbol, double rate)
        : amount(amount), currencycode(code), currencysymbol(symbol), exchangerate(rate) {}

    virtual void Convertobase() = 0;
    virtual void Convertotarget(Currency* targetcurrency) = 0;
    virtual void displayCurrency() = 0;

    
};


class Dollar : public Currency {
public:
    Dollar(double amount,double rate=1.0) : Currency(amount, "USD", "$", rate) {}

    void Convertobase() override {
        amount /= exchangerate;
    }

    void Convertotarget(Currency* targetcurrency) override {
        Convertobase();  // Convert this amount to base currency (USD)
        amount *= targetcurrency->exchangerate;  // Convert base amount to target currency
        cout << "Converting " << currencycode << " into " << targetcurrency->currencycode << endl;
    }

    void displayCurrency() override {
        cout << "Amount: " << currencysymbol << amount << " (" << currencycode << " )" << endl;
    }
};

// Euro class
class Euro : public Currency {
public:
    Euro(double amount,double rate=0.91) : Currency(amount, "EUR", "€", rate) {} // 1 EUR = 1.1 USD

    void Convertobase() override {
        amount /= exchangerate;
    }

    void Convertotarget(Currency* targetcurrency) override {
        Convertobase();  // Convert this amount to base currency (USD)
        amount *= targetcurrency->exchangerate;  // Convert base amount to target currency
        cout << "Converting " << currencycode << " into " << targetcurrency->currencycode << endl;
    }

    void displayCurrency() override {
        cout << "Amount: " << currencysymbol << amount << " (" << currencycode << " )" << endl;
    }
};

// Rupee class
class Rupee : public Currency {
public:
    Rupee(double amount,double rate=83.0) : Currency(amount, "PKR", "Rs", rate) {} // 1 USD = 83 PKR

    void Convertobase() override {
        amount /= exchangerate;
    }

    void Convertotarget(Currency* targetcurrency) override {
        Convertobase();  // Convert this amount to base currency (USD)
        amount *= targetcurrency->exchangerate;  // Convert base amount to target currency
        cout << "Converting " << currencycode << " into " << targetcurrency->currencycode << endl;
    }

    void displayCurrency() override {
        cout << "Amount: " << currencysymbol << amount << " (" << currencycode << " )" << endl;
    }
};

// Main function
int main() {
    Currency* array[3];
    array[0] = new Dollar(235);
    array[1] = new Euro(450);
    array[2] = new Rupee(8900);

    cout << "\nBefore Conversion:\n";
    for (int i = 0; i < 3; i++) {
        array[i]->displayCurrency();
    }

    cout << "\nConverting Some Currency:\n";
    array[0]->Convertotarget(array[1]); 
    array[1]->Convertotarget(array[2]); 
    array[2]->Convertotarget(array[0]); 

    cout << "\nAfter Conversions:\n";
    for (int i = 0; i < 3; i++) {
        array[i]->displayCurrency();
    }

  
    for (int i = 0; i < 3; i++) {
        delete array[i];
    }

    return 0;
}
