/*Q1. You are building a student record management tool for a university system.
Requirements:
1. Define a structure Student with the following fields:
○ int id
○ string name
○ float gpa
2. Prompt the user to enter data for 5 students.
3. Write these records to a file named students.txt using ofstream with ios::out
mode.
4. Then, allow the user to append 1 additional student record using ios::app mode
(open in append mode and write without erasing old content).
5. Finally, read and display all student records from the file using ifstream.*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student{
    int id;
    string name;
    float gpa;
};
int main(){
   // Student s[5];
   Student *s;
   int studcount=0;
   string name,line;
   int id;
   float gpa;
      ofstream file;
    ifstream filein;
    file.open("student.txt",ios::out|ios::app);
    if(!file.is_open()){
        cout<<"File not opened soory"<<endl;
        return 1;
    }
    for (int i=0;i<5;i++){
        cout<<"Enter the details of Student "<<i+1<<endl;
        cout<<"Id: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        cout<<"GPA: ";
        cin>>gpa;
        s = new Student[1];
        s->name = name;
        s->id = id;
        s->gpa = gpa;
       // studcount++;
        if(file.is_open()){
        file << s->id;
        file<<" ";
        file << s->name;
        file<<" ";
        file << s->gpa;
        file <<"\n";
    }
    delete []s;
    }
 
    
    cout<<"Appending the student in file"<<endl;
     cout<<"Enter the details of Student "<<endl;
        cout<<"Name: ";
        cin>>name;
        cout<<"Id: ";
        cin>>id;
        cout<<"GPA: ";
        cin>>gpa;
        s = new Student[1];
        s->name = name;
        s->id = id;
        s->gpa = gpa;
       // studcount++;
      file << s->id;
        file<<" ";
        file << s->name;
        file<<" ";
        file << s->gpa;
        file <<"\n";
       delete []s;
    if(file.is_open()){
    file.close();
    cout<<"File is closed"<<endl;
    }
    
    filein.open("student.txt");
    if(filein.is_open()){
    while (getline(filein,line)){
          cout <<line<<endl;
    }
     filein.close();
    }
    else cout<<"Unable to open file"<<endl;

    return 0;
}