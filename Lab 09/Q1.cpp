/*Task 01
Problem: A vehicle rental company is expanding its services to include cars, bikes, and
future vehicle types. They need a flexible system to manage daily rates and display vehicle
details without exposing internal calculations. The goal is to ensure new vehicle types (e.g.,
scooters, trucks) can be added seamlessly while maintaining a consistent interface for
customers to view rental options.
Classes and Structure:
• Abstract Class Vehicle:
o Data Members:
▪ model (string): Stores the vehicle’s model name.
▪ rate (double): Stores the daily rental rate.
o Member Functions:
▪ getDailyRate(): Pure virtual function to return the daily rate.
▪ displayDetails(): Pure virtual function to show model and rate.

• Derived Class Car:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide car-specific
behavior.
• Derived Class Bike:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide bike-specific
behavior.

Flow:
• Create Car and Bike objects.
• Use polymorphism to call displayDetails() and getDailyRate() for each vehicle.*/
#include<iostream>
using namespace std;
class Vehicle{
    protected:
    string model;
    double rate;
    public:
    Vehicle(string name="",double rate =0):model(name),rate(rate){}
   virtual double getDailyRate()=0;
   virtual void displaydetails()=0;
};
class Car: public Vehicle{
    public:
    Car(string name="",double rate =0):Vehicle(name,rate){}
    double getDailyRate()override{
    return rate;
    }
    void displaydetails()override{
        cout<<"Car model: "<<model<<endl;
       // cout<<"Rate: "<<getDailyRate()<<endl;
    }

};
class Bike: public Vehicle{
    public:
    Bike(string name="",double rate =0):Vehicle(name,rate){}
    double getDailyRate()override{
    return rate;
    }
    void displaydetails()override{
        cout<<"Bike model: "<<model<<endl;
        //cout<<"Rate: "<<getDailyRate()<<endl;
    }

};
int main(){
    Vehicle *ptr;
    Car c("2014",670000);
    Bike b("2020",45000);
    ptr = &c;
    ptr->displaydetails();
    cout<<"Rate: "<<ptr->getDailyRate()<<endl;
    ptr = &b;
    ptr->displaydetails();
    cout<<"Rate: "<<ptr->getDailyRate()<<endl;

}

