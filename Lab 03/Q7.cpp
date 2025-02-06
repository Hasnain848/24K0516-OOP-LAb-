#include <iostream>
#include <iomanip>
using namespace std;
class Stationary
{
private:
    string *product = new string[0];
    float *prices = new float[0];
    int product_count = 0;

public:
    void Add_items()
    {
        int n;
        cout << "Number Of products to add: ";
        cin >> n;
        string *temp_product = new string[n];
        float *temp_prices = new float[n];
        for (int i = 0; i < product_count; i++)
        {
            temp_product[i] = product[i];
            temp_prices[i] = prices[i];
        }
        delete[] product;
        delete[] prices;

        product = temp_product;
        prices = temp_prices;
        cout << "Enter the Products Details" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Product name: ";
            cin >> product[i];
            cout << "Set price: ";
            cin >> prices[i];
        }
        cout << "Products added succesfully" << endl;
        product_count += n;
    }
    void FetchItems()
    {
        if (product_count == 0)
        {
            cout << "Error: No Product to show :(" << endl;
            return;
        }
        cout << "========== Products ==========" << endl;
        for (int i = 0; i < product_count; i++)
        {
            cout << i + 1 << ". " << product[i] << endl;
        }
    }
    void display_all()
    {
        if (product_count == 0)
        {
            cout << "Error: No Product to show :(" << endl;
            return;
        }
        cout << "========== ALL Products ==========" << endl;
        for (int i = 0; i < product_count; i++)
        {
            cout << i + 1 << ". " << product[i] << "-> " << prices[i] << endl;
        }
    }
    void Edit_price()
    {
        int n;
        float new_price;
        if (product_count == 0)
        {
            cout << "Error: Zero Products :(" << endl;
            return;
        }
        cout << "========== Products ==========" << endl;
        for (int i = 0; i < product_count; i++)
        {
            cout << i + 1 << ". " << product[i] << endl;
        }
        cout << "Enter the Product no to change: ";
        cin >> n;
        cout << "Enter the new price ";
        cin >> new_price;
        prices[n - 1] = new_price;
        cout << "Price updated :)" << endl;
    }
    void print_receipt()
    {
        if (product_count == 0)
        {
            cout << "Error:Sorry we are OUT OF STOCK :(" << endl;
            return;
        }
        int *quantities = new int[product_count]();
        char more;
        double totalAmount = 0;
        do
        {
            FetchItems();
            int choice, qty;
            cout << "Enter the item number to purchase: ";
            cin >> choice;
            if (choice < 1 || choice > product_count)
            {
                cout << "Invalid choice! Try again.\n";
                continue;
            }
            cout << "Enter quantity for " << product[choice - 1] << ": ";
            cin >> qty;
            quantities[choice - 1] += qty;
            totalAmount += prices[choice - 1] * qty;

            cout << "Do you want to add more items? (y/n): ";
            cin >> more;
        } while (more == 'y' || more == 'Y');
        cout << "\n**********************Receipt***********************\n";
        cout << "Product             Qty      Price     Total" << endl;
        cout << "-----------------------------------------------------" << endl;
        for (int i = 0; i < product_count; i++)
        {
            if (quantities[i] > 0)
            {
                cout << setw(20) << left << product[i] << setw(10) << quantities[i]
                     << setw(10) << prices[i] << setw(10) << prices[i] * quantities[i] << endl;
            }
        }
        cout << "----------------------------------------------------\n";
        cout << setw(40) << left << "Grand Total:" << "Rs. " << fixed << setprecision(2) << totalAmount << endl;
        cout << "******** THANK YOU! ********\n";

        delete[] quantities;
    }
};
int main()
{
    Stationary shop;
    int choice;

    do
    {
        cout << "\n========== Stationary Shop Menu ==========\n";
        cout << "1. Add Items\n";
        cout << "2. Fetch Items\n";
        cout << "3. Edit Prices\n";
        cout << "4. View Items and Prices\n";
        cout << "5. Print Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            shop.Add_items();
            break;
        case 2:
            shop.FetchItems();
            break;
        case 3:
            shop.Edit_price();
            break;
        case 4:
            shop.display_all();
            break;
        case 5:
            shop.print_receipt();
            break;
        case 6:
            cout << "Exiting the program. Have a nice day!\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}