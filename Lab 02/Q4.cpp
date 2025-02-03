#include<iostream>
using namespace std;
int* memory_allocation(int size);
void uniquie(int *arr,int size,int *result,int *numsize);
int main(){
int* array,*result;
int numsize,n;
cout<<"Enter the size of array: ";
cin>>n;
array=memory_allocation(n);
result=memory_allocation(n);
for(int i=0;i<n;i++){
    cout<<"Enter element "<<i+1<<" : ";
    cin>>array[i];
}
uniquie(array,n,result,&numsize);
cout<<"\nUnique Elements are: ";
for(int i=0;i<numsize;i++){
    cout<<result[i]<<",";
}
}
int* memory_allocation(int size){
    int *array = new int[size];
    if (!array)
    {
        cout << "Error in memory allocation" << endl;
        return nullptr;
    }
   return array;
}
void uniquie(int *arr,int size,int *result,int *numsize){
   *numsize=0;
for(int i=0;i<size;i++){ 
     int found=0;
     for(int j=0;j<*numsize;j++){
        if(arr[i]==result[j]){
          found=1;
          break;}
     }
        if(!found){
            result[*numsize]=arr[i];
            (*numsize)++;
        }          
}
}