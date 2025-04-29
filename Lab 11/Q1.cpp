#include<iostream>
using namespace std;
class  InvalidValueException : public exception{
    public:
    const char* what() const noexcept override{
        return("Error: InvalidValueException - Age cannot be negative or exceed 120.");
    }

};
int main(){
    int age;
    cout<<"Enter the your Age: ";
    cin>>age;
    try{
        if(age<0 || age>120)throw InvalidValueException();
        cout<<"Your age: "<<age<<endl;
    }
    catch(InvalidValueException e){
        cout<<e.what();
    }
}