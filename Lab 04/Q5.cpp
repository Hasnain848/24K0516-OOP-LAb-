#include<iostream>
using namespace std;
class Employee{
    private:
    int employeeid;
    string name,department;
    double salary;
    public:
    Employee(){
        salary=0.0;
    }
    Employee(int employeeid,string name,string department,double salary){
        this->employeeid=employeeid;
        this->name=name;
        this->department=department;
        this->salary=salary;
    }
    void giveBonus(double amount){
        if(amount<0){
            cout<<"Invalid Bonus"<<endl;
            return;
        }
        salary+=amount;
    }
    bool isManager(){
        if(department=="Management"){
            return true;
        }
        else return false;
    }
    void displayDetails(){
        cout<<"-----------Employee Details---------------"<<endl;
        cout<<"Id: "<<employeeid<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"------------------------------------------"<<endl;
    }
};
int main(){
     Employee emp1(101, "John Doe", "IT", 50000);
     Employee emp2(102, "Alice Smith", "Management", 70000);
     emp1.displayDetails();
     emp2.displayDetails();
     emp1.giveBonus(5000);
     emp2.giveBonus(10000);
     cout << "After Bonus:" << endl;
     emp1.displayDetails();
     emp2.displayDetails();
     cout << (emp1.isManager() ? "Emp1 is a Manager" : "Emp1 is not a Manager" )<< endl;
     cout << (emp2.isManager() ? "Emp2 is a Manager" : "Emp2 is not a Manager" )<< endl;
 
     return 0;

}