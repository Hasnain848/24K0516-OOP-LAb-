#include<iostream>
using namespace std;

int main(){
 int n;
 cout<<"Enter the number of students: ";
 cin>>n;
int **arr= new int* [n];
for(int i=0;i<n;i++){
 arr[i]=new int [3];
}
float *average= new float[n];

 for(int j=0;j<n;j++){
  int sum =0;
  cout<<"Enter the Details for Student "<<j+1<<" "<<endl;
  cout<<"Enter the marks"<<endl;
  for(int i=0;i<3;i++){
  cout<<"Marks "<<i+1<<": ";
  cin>>arr[j][i];
  sum = sum+arr[j][i];
 }
 average[j]=sum/3;
 }
 for(int i=0;i<n;i++){
 cout<<"Details of student "<<i+1<<" "<<endl;
 for(int j=0;j<3;j++){
  cout<<"Marks "<<j+1<<" : "<<arr[i][j]<<endl;

 }
 cout<<"Average: "<<average[i]<<endl;
 if(average[i]>=90) cout<<"Grade: A"<<endl;
 else if(average[i]>=80 && average[i]<=89) cout<<"Grade: B"<<endl;
 else if(average[i]>=70 && average[i]<=79) cout<<"Grade: C"<<endl;
 else if(average[i]>=60 && average[i]<=69) cout<<"Grade: D"<<endl;
 else cout<<"Grade: F"<<endl;

 }
for(int i=0;i<n;i++){
 delete[] arr[i];
}
delete[] arr;
  
  }