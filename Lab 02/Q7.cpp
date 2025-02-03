#include <iostream>
#include <cstdlib> 
using namespace std;

struct Product {
    int product_id;
    string name;
    int quantity;
    float price;
};
Product* products = nullptr;
int product_count = 0;
int capacity = 2; 
void addproduct(int id, string n1, float p1, int q1);
void product_finder(int pro_id);
void update_product(int pro_id, float p1, int q1);
void remove_product(int pro_id);
int main() {
  
    products = (Product*)malloc(capacity * sizeof(Product));
    
    addproduct(1, "Laptop", 799.99, 50);
    addproduct(2, "Smartphone", 499.99, 100);
    
    product_finder(1);
    
    update_product(1, 749.99, 45);
    
    product_finder(1);
    
    remove_product(2);
    
    product_finder(2);
    
    
    free(products);
    return 0;
}
void addproduct(int id, string n1, float p1, int q1) {
    if (product_count >= capacity) {
        capacity *= 2; 
        products = (Product*)realloc(products, capacity * sizeof(Product));
        if (!products) {
            cout << "Memory allocation failed" << endl;
            exit(1);
        }
    }
    
    products[product_count].product_id = id;
    products[product_count].name = n1;
    products[product_count].quantity = q1;
    products[product_count].price = p1;
    product_count++;
    cout << "Product added successfully" << endl;
}
void product_finder(int pro_id) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].product_id == pro_id) {
            cout << "Product id: " << products[i].product_id << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: " << products[i].price << endl;
            cout << "Quantity in Stock: " << products[i].quantity << endl;
            return;
        }
    }
    cout << "Sorry, product not found" << endl;
}
void update_product(int pro_id, float p1, int q1) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].product_id == pro_id) {
            products[i].price = p1;
            products[i].quantity = q1;
            cout << "Record updated successfully" << endl;
            return;
        }
    }
    cout << "Sorry, product not found" << endl;
}
void remove_product(int pro_id) {
    for (int i = 0; i < product_count; i++) {
        if (products[i].product_id == pro_id) {
            for (int j = i; j < product_count - 1; j++) {
                products[j] = products[j + 1];
            }
            product_count--;
            cout << "Product removed successfully." << endl;
            return;
        }
    }
    cout << "Sorry, product not found" << endl;
}
