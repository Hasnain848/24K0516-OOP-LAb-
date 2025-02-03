/*
A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized.
Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should
display the value of this third variable. Make appropriate member functions const.*/

#include<iostream>
using namespace std;
class Time{
private:
int hrs;
int minutes;
int sec;
public:
Time(){
    hrs=0;
    minutes=0;
    sec=0;
}
Time(int hr,int min,int se){
    hrs=hr;
    minutes=min;
    sec=se;
}
void display(){
    cout<<hrs<<":"<<minutes<<":"<<sec<<endl;
}
 Time addTime(Time t1){
    Time temp;
    temp.hrs=hrs+t1.hrs;
    temp.minutes=minutes+t1.minutes;
    temp.sec=sec+t1.sec;
    return temp;
}

};
int main(){
Time time1(2,34,56),t2(3,10,2),t3;
t3=time1.addTime(t2);
t3.display();

}



