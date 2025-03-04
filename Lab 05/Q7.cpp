
#include <iostream>
using namespace std;
class Menuitems
{
    string foodname;
    float foodprice;

public:
    Menuitems(string name = "", float price = 0.0) : foodname(name), foodprice(price) {}

    string getfoodname() { return foodname; }
    float getfoodprice() { return foodprice; }

    void display()
    {
        cout << "Food: " << foodname << "  Price: Rs" << foodprice << endl;
    }
};
class Menu
{
    Menuitems menuitem[2];
    int count;

public:
    Menu() : count(0) {}
    void addfood(Menuitems m)
    {
        if (count < 2)
        {
            menuitem[count] = m;
            count++;
            cout << "Item has been added" << endl;
            return;
        }
        else
            cout << "No more item will be added" << endl;
    }
    void removeitem(Menuitems m)
    {
        for (int i = 0; i < 2; i++)
        {
            if (menuitem[i].getfoodname() == m.getfoodname())
            {
                cout << "Item is removed" << endl;
                for (int j = i; j < 2; j++)
                {
                    menuitem[j] = menuitem[j + 1];
                }
                break;
            }
        }
    }
    void displaymenu()
    {
        cout << "===========Menu============" << endl;
        for (int i = 0; i < 2; i++)
        {
            menuitem[i].display();
        }
        cout << "===========================" << endl;
    }
    Menuitems getItem(int index)
    {
        if (index >= 0 && index < 2)
            return menuitem[index];
        return Menuitems();
    }
};
class Payment
{
public:
    double amount;

    Payment() : amount(0.0) {}
    Payment(double amt) : amount(amt) {}

    void processPayment() const
    {
        cout << "Payment of Rs" << amount << " received. Thank you!" << endl;
    }
};

class Order
{
private:
    Menuitems orderedItems[2]; // Fixed size of 2
    int itemCount;
    Payment payment;

public:
    Order() : itemCount(0), payment(0) {}

    void addItem(Menuitems item)
    {
        if (itemCount < 2)
        {
            orderedItems[itemCount++] = item;
            cout << item.getfoodname() << " added to order." << endl;
        }
        else
        {
            cout << "Order can only contain 2 items!" << endl;
        }
    }

    void finalizeOrder()
    {
        double total = 0.0;
        cout << "\n--- Order Summary ---\n";
        for (int i = 0; i < itemCount; i++)
        {
            orderedItems[i].display();
            total += orderedItems[i].getfoodprice();
        }
        payment = Payment(total);
        cout << "Total Amount: Rs" << total << endl;
        cout << "----------------------\n";
        payment.processPayment();
    }
};

class RestaurantOrderingSystem
{
private:
    Menu menu;

public:
    RestaurantOrderingSystem()
    {

        Menuitems m1("Burger", 700), m2("Pizza", 1500);
        menu.addfood(m1);
        menu.addfood(m2);
    }

    void takeOrder()
    {
        Order order;
        int choice;
        menu.displaymenu();
        cout << "Select 2 items to order:\n";

        for (int i = 0; i < 2; i++)
        {
            cout << "Enter item number: ";
            cin >> choice;
            order.addItem(menu.getItem(choice - 1));
        }

        order.finalizeOrder();
    }
};

int main()
{
    RestaurantOrderingSystem restaurant;
    restaurant.takeOrder();
    return 0;
}
