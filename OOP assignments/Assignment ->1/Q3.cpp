#include <iostream>
using namespace std;

class Register {
private:
    string name1, type1;
    int id1, age1, number1;

public:
    Register(string name, int id, int age, string type, int number)
        : name1(name), type1(type), age1(age), number1(number), id1(id) {}

    void updateDetails() {
        cout << "Enter new Name: ";
        cin >> name1;
        cout << "New ID: ";
        cin >> id1;
        cout << "Enter new Age: ";
        cin >> age1;
        cout << "Enter new License type (Learner/Intermediate/Full): ";
        cin >> type1;
        cout << "Contact new number: ";
        cin >> number1;
        cout << "Information updated successfully!" << endl;
    }

    string getLicenseType() { return type1; }
    void displayUserDetails() {
        cout << "User: " << name1 << ", ID: " << id1 << ", Age: " << age1
             << ", License Type: " << type1 << ", Contact: " << number1 << endl;
    }
};

class Vehicle {
private:
    string name, eligibility;
    int model, car_cc;
    float rentalPrice;

public:
    Vehicle(string n, int m, int cc, float price, string eligible)
        : name(n), model(m), car_cc(cc), rentalPrice(price), eligibility(eligible) {}

    void displayVehicle() {
        cout << "\n-------------------------------------" << endl;
        cout << "Car Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << car_cc << " cc" << endl;
        cout << "Rental Price per day: $" << rentalPrice << endl;
        cout << "Eligibility: " << eligibility << " License Required" << endl;
        cout << "-------------------------------------" << endl;
    }

    bool isEligible(string licenseType) {
        return licenseType == eligibility;
    }
};

int main() {
  string name, type;
    char choice;
    int id, age, number;
    cout << "==============================" << endl;
    cout << "| MY Name: M Hasnain Siddiqui |" << endl;
    cout << "| Roll num: 24K-0516         |" << endl;
    cout << "==============================" << endl;
    cout << "--------- Register Page --------------" << endl;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore(); 
    cout << "Enter License type (Learner/Intermediate/Full): ";
    getline(cin, type);
    cout << "Contact number: ";
    cin >> number;

    Register user(name, id, age, type, number);

    cout << "Do you want to edit your details? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        user.updateDetails();
    }

    int vehicleCount = 3;
    Vehicle *vehicles[3];

    vehicles[0] = new Vehicle("Toyota Corolla", 2022, 1600, 50.0, "Learner");
    vehicles[1] = new Vehicle("Honda Civic", 2023, 1800, 60.0, "Intermediate");
    vehicles[2] = new Vehicle("BMW X5", 2023, 3000, 120.0, "Full");

    cout << "\nAvailable Vehicles: " << endl;
    for (int i = 0; i < vehicleCount; i++)
    {
        vehicles[i]->displayVehicle();
    }

    cout << "\nEnter the number of the vehicle you want to rent (1-3): ";
    int choiceVehicle;
    cin >> choiceVehicle;

    if (choiceVehicle >= 1 && choiceVehicle <= vehicleCount)
    {
        Vehicle *selectedVehicle = vehicles[choiceVehicle - 1];

        if (selectedVehicle->isEligible(user.getLicenseType()))
        {
            cout << "Rental Successful! You have rented the vehicle." << endl;
        }
        else
        {
            cout << "Sorry, you are not eligible to rent this vehicle." << endl;
        }
    }
    else
    {
        cout << "Invalid selection." << endl;
    }

    
    for (int i = 0; i < vehicleCount; i++)
    {
        delete vehicles[i];
    }

    return 0;
}
