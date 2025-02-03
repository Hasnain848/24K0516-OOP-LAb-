#include<iostream>
#include<conio.h>
using namespace std;
class Toolbooth{
private:
unsigned int Total_num_cars;
double moneyCollected;

public:
Toolbooth(){
    Total_num_cars=0;
    moneyCollected=0;
}
void payingCar()
{
    Total_num_cars++;
    moneyCollected+=0.50;
}
void nopay(){
     Total_num_cars++;
}
void display(){
    cout<<"\nTotal cars passed: "<<Total_num_cars<<endl;
    cout<<"Total money Collected: "<<moneyCollected<<endl;
}};

int main(){
   
Toolbooth t1;
char choice;
 cout<<"\nP: Paying cars\nN: Nonpaying cars\nEsc for Exit ";
while(true){
    cout<<"\nChoice: ";
    choice=getche();

    switch(choice){
        case 'P':
        case 'p':t1.payingCar();break;
        case 'N':
        case 'n':t1.nopay();break;
        case 27:t1.display(); return 0;
        default:
        cout<< "invalid choice"<<endl;
        
                
    }
   
}
 return 0;
}