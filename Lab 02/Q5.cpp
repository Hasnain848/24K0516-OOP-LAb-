#include<iostream>
#include<cstring>
using namespace std;
void swaping(char* str,int shift,int times);
int main(){
char str[100];
int n;
cout<<"enter String: ";
 cin.getline(str, 100);
cout<<"Enter the numbers of characters to shift: ";
cin>>n;
swaping(str,n,n);
cout<<"Shifted string after shifting last "<<n<<" characters: "<<str<<endl;
}
void swaping(char* str,int shift,int times){
    int len=strlen(str);
    char temp[len];
    for(int i=0;i<times;i++){
        strncpy(temp,str+len-shift,shift);
        strncpy(temp+shift,str,len-shift);
        temp[len]='\0';
    }
     strcpy(str,temp);
}