#include<iostream>
using namespace std;
class Car{
    int carID;
    string model;
    int year;
    bool isRented;
    public:
    Car(){
        isRented=false;
    }
    Car(int id,string mode,int yer,bool rent){
        carID=id;
        model=mode;
        year=yer;
        isRented=rent;
    }
    void rentaCar(){
        isRented=true;
        cout<<"\nCar rented"<<endl;
    }
    void returnCar(){
        isRented=false;
        cout<<"\nCar returned"<<endl;
    }
    bool isVintage(){
        if(year<2000){
            return true;
        }
        return false;
    }
void displayInfo() {
        cout << "Car ID: " << carID << "\nModel: " << model 
             << "\nYear: " << year << "\nRented: " << (isRented ? "Yes" : "No") << endl;
    }
};

int main() {
    Car car1(101, "Toyota Corolla", 1995, false);
    Car car2(102, "Honda Civic", 2022, false);
    cout << "Car 1 details:" << endl;
    car1.displayInfo();
    cout << "\nCar 2 details:" << endl;
    car2.displayInfo();
    car1.rentaCar();
    car1.displayInfo();
    car1.returnCar();
    car1.displayInfo();
    cout << "\nCar 1 is vintage: " << (car1.isVintage() ? "Yes" : "No") << endl;
    cout << "Car 2 is vintage: " << (car2.isVintage() ? "Yes" : "No") << endl;

    return 0;
}