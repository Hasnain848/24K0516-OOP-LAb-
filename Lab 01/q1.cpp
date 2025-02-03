#include<iostream>
using namespace std;
void is_prime(int num){
int depender=1;
for(int i=2;i<num;i++){
 depender=depender*(num%i);
 }
 if (depender==0)
 printf("not prime");
 else
 printf("prime");
}
int main(){
 int a;
 cout<<"Enter the number";
 cin>>a;
 is_prime(a);
}