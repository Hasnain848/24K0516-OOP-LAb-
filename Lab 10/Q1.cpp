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
   Student s;
   int studcount=0;
   string line;
   int counter;
   float gpa;
      ofstream file;
    ifstream filein;
    file.open("student.txt",ios::out|ios::app);
    if(!file.is_open()){
        cout<<"File not opened soory"<<endl;
        return 1;
    }
    file <<"Id\tName\t\t\tGPA\n";
    cout<<"Enter the number of students you want to add"<<endl;
    cin>>counter;
    for (int i=0;i<counter;i++){
        cout << "Enter the details of Student " << i + 1 << endl;
        cout << "Id: ";
        cin >> s.id;

        cin.ignore(); 
        cout << "Name: ";
        getline(cin, s.name); 

        cout << "GPA: ";
        cin >> s.gpa;
        file << s.id << "\t" << s.name << "\t\t\t" << s.gpa << "\n";
    }
 
    //--------------------------------------------------------
    cout<<"Appending the student in file"<<endl;
     cout<<"Enter the details of Student "<<endl;
        cout<<"Name: ";
        cin>>s.name;
        cout<<"Id: ";
        cin>>s.id;
        cout<<"GPA: ";
        cin>>s.gpa;
    file << s.id << "\t" << s.name << "\t\t\t" << s.gpa << "\n";
    //---------------------------------------------------------
    if(file.is_open()){
    file.close();
    cout<<"==========================="<<endl;
    cout<<"||  File is closed        ||"<<endl;
    cout<<"==========================="<<endl;
    }
    
    filein.open("student.txt");
    cout<<"==============Displaying Data from file==============="<<endl;
    if(filein.is_open()){
    while (getline(filein,line)){
          cout <<line<<endl;
    }
     filein.close();
    }
    else cout<<"Unable to open file"<<endl;

    return 0;
}