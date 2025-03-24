#include<iostream>
using namespace std;
class temp{
    private:
int a;
public:
temp(int a=0):a(a){}
friend temp& operator+=( temp& obj,const temp&obj2);
void display()const{
    cout<<"Value: "<<a<<endl;
}
};
temp&operator+=( temp& obj,const temp&obj2){
    obj.a+=obj2.a;
    return obj;
}

int main() {
   temp obj1(10), obj2(20);
    obj1 += obj2; 
    obj1.display(); 

    return 0;
}
