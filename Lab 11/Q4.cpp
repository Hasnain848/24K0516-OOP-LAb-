#include<iostream>
#include<math.h>
using namespace std;
class NegativeNumberException: public exception{
    public:
    const char* what() const noexcept override{
        return("Negative Number Exception -> Input must be non negative.");
    }
};
class InvalidTypeException: public exception{
    public:
    const char* what() const noexcept override{
        return("Invalid Type Exception -> Non Numeric type is detected.");
    }
};
template <typename T>
double mysqrt(T num){
    
    return sqrt(num);
}
int main(){
    int num;
    double result;
    try{
    cout<<"Enter the num :";
    cin>>num;
    if(cin.fail()) throw InvalidTypeException();
    if(num<0)throw NegativeNumberException();
    result = mysqrt(num);
    cout<<"Squre root is "<<result<<endl;
}
catch(const  InvalidTypeException &e){
    cout<<e.what();
}
catch(const NegativeNumberException &e){
    cout<<e.what();
}
}