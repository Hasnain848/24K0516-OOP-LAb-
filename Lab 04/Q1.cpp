#include<iostream>
using namespace std;
class Student{
    private:
    int studentid;
    string name;
    int age;
    char grade;
    public:
    //Default Constructor
    Student(){
        studentid=0;
        age=0;
        name="";
        grade='N';
    }
    // Paramitarize Constructor
    Student(int studentid,string  name,int age,char grade){
        this->studentid=studentid;
        this->age=age;
        this->name=name;
        this->grade=grade;
    }
    void Promotestudent(){
        if(grade=='A'||grade=='a'){
            return;
        }
        grade--;
    }
    bool isEligibleForScholarship(){
        if(grade=='A'||grade=='a'){
            return true;
        }
        return false;
    }
    void display(){
        cout<<"\n-----------Students Detail------------"<<endl;
        cout<<"Student ID: "<<studentid<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Grade: "<<grade<<endl;
    }

};
int main(){
    Student s1;
    Student s2(1234,"Obaid",75,'B');

    s1.display();
    s2.display();
    cout<<"\n Promoting Student 2 "<<endl;
    s2.Promotestudent();
    s2.display();
    cout<<"-----------Eligiblity---------------------"<<endl;
    int eligible=s1.isEligibleForScholarship();
    if(eligible==1){
    cout<<"Eligible for Scholarship for student 1: True"<<endl;
    }
    else{
        cout<<"Eligible for Scholarship for student 1: False"<<endl;
    }
    int eligible1=s2.isEligibleForScholarship();
    if(eligible1==1){
    cout<<"Eligible for Scholarship for student 2: True"<<endl;
    }
    else{
        cout<<"Eligible for Scholarship student 2: False"<<endl;
    }
    
    
}