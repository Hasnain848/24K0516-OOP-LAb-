#include<iostream>
using namespace std;
class StackOverflowException : public exception{
    public:
    const char* what() const noexcept override{
        return("Stack is full.");
    }
};
class StackUnderflowException : public exception {
    public:
    const char* what() const noexcept override{
        return("Stack is empty.");
    }
};
template <typename T>
class Stack{
    static const int max = 5;//
    T array[max];
    int top ;
    public:
    Stack():top(-1){}
    void push(T value){
        if (top >= max - 1) throw StackOverflowException();
        array[++top]=value;
        return;
    }
    T pop(){
        if(top<0)throw StackUnderflowException();
        return array[top--];
    }
};
int main(){
    Stack<int> s;
    // With Stack Overflow exception
    try{
        s.push(5);
        s.push(6);
        s.push(7);
        s.push(8);
        s.push(9);
        //now we are adding more than 5 elements
        s.push(90);
        cout<<"All numbers added "<<endl;
    }
    catch (const exception& e){
        cout<< "Exception caught: " <<e.what();
    }
    // Stack underflow exception
    try{
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        // now since we already pop the 5 elements now if we try to once again pop the element then it throw exception
        s.pop();
        
    }
    catch (const exception& e){
        cout<< "\nException caught: " <<e.what();
    }
    return 0;
}