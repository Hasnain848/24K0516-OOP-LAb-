#include <iostream>
using namespace std;
class Product
{
protected:
    string productID;
    double price;

public:
    Product(string id, double price) : productID(id), price(price) {}
    virtual double Calculateprice() = 0;

    void discount(double percentage)
    {
        price -= (price * (percentage / 100));
        cout << "Applied " << percentage << "% discount. New price: " << price << endl;
    }
    void discount(int fixeddiscount)
    {
        price -= fixeddiscount;
        cout << "Applied " << fixeddiscount << " discount. New price: " << price << endl;
    }
    void discount(string offer)
    {
        if (offer == "BOGO")
        {
            cout << "Buy One Get One Free applied! Pay for one, get two products!" << endl;
        }
        else
        {
            cout << "Invalid offer!" << endl;
        }
    }
    string getid() { return productID; }
    double getprice() { return price; }
};
class Electronics : public Product
{
public:
    Electronics(string id, double price) : Product(id, price) {}
    double Calculateprice() override
    {
        return price * 1.15;
    }
};
class Clothing : public Product
{
public:
    Clothing(string id, double price) : Product(id, price) {}
    double Calculateprice() override
    {
        return price * 1.05;
    }
};
class Shoppingcart
{
    Product *p[10];
    int itemcount;
    double totalcost;

public:
    Shoppingcart() : itemcount(0), totalcost(0) {}

    void additem(Product *item)
    {
        if (itemcount < 10)
        {
            p[itemcount] = item;
            totalcost += item->Calculateprice();
            itemcount++;
            cout << "Item added" << endl;
        }
        else
            cout << "Sorry limit reached cart is full" << endl;
    }
    void displayCart()
    {
        cout << "\nShopping Cart Items:\n";
        for (int i = 0; i < itemcount; i++)
        {
            cout << "Product ID: " << p[i]->getid() << ", Price: " << p[i]->getprice() << endl;
        }
        cout << "Total Cost: " << totalcost << endl;
    }
    Shoppingcart operator+(const Shoppingcart &obj)
    {
        Shoppingcart newcart = *this;
        for (int i = 0; i < obj.itemcount; i++)
        {
            if (newcart.itemcount < 10)
            {
                newcart.p[newcart.itemcount] = obj.p[i];
                newcart.totalcost += obj.p[i]->Calculateprice();
                newcart.itemcount++;
            }
        }
        return newcart;
    }
    Shoppingcart operator-(const string id)
    {
        Shoppingcart newcart;
        bool remove = false;
        for (int i = 0; i < itemcount; i++)
        {
            if (p[i]->getid() == id && !remove)
            {
                remove = true;
            }
            else
                newcart.additem(p[i]);
        }
        return newcart;
    }
    Shoppingcart operator*(double discount)
    {
        Shoppingcart newcart = *this;
        newcart.totalcost *= (1 - discount / 100);
        return newcart;
    }
    double operator/(int user)
    {
        if (user <= 0)
            return 0;
        return totalcost / user;
    }
};
int main()
{

    Electronics laptop("E1001", 1000);
    Clothing shirt("C2001", 50);

    cout << "--- Applying Discounts ---" << endl;
    laptop.discount(10);
    shirt.discount(20);
    laptop.discount("BOGO");

    Shoppingcart cart1, cart2;
    cart1.additem(&laptop);
    cart2.additem(&shirt);

    cout << "\n--- Displaying Individual Carts ---" << endl;
    cout << "Cart 1:\n";
    cart1.displayCart();
    cout << "\nCart 2:\n";
    cart2.displayCart();

    Shoppingcart mergedCart = cart1 + cart2;
    cout << "\n--- Merged Cart ---" << endl;
    mergedCart.displayCart();

    Shoppingcart discountedCart = mergedCart * 5;
    cout << "\n--- After 5% Discount ---" << endl;
    discountedCart.displayCart();

    Shoppingcart updatedCart = discountedCart - "E1001";
    cout << "\n--- After Removing Laptop ---" << endl;
    updatedCart.displayCart();

    double splitCost = mergedCart / 2;
    cout << "\nEach User Pays: $" << splitCost << endl;

    return 0;
}
