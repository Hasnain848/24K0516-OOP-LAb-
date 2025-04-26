/*Q2. A user wishes to update their resume in your Resume Builder application.
Requirements:
1. Prompt the user to enter:
○ string name
○ string email
○ int yearsOfExperience
○ string summary
2. Write this data to a file called resume.txt.
3. Use ofstream with ios::trunc to ensure that any previous contents are completely
deleted before writing new data.
4. After writing, read back and display the contents to confirm that the file only has the
latest entry.*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string temp;
    int experience;
    ofstream fileout("resume.txt",ios::trunc);
    if(!fileout.is_open()){
        cout<<"File not opened soory"<<endl;
        return 1;
    }
    fileout <<"\t\t\tReume\t\t\t\n";
    cout<<"=========Enter the Details=========="<<endl;
    cout<<"Name: ";
    getline(cin,temp);
    fileout<<"Name:\t\t"<<temp<<"\n";
    cout<<"Email: ";
    getline(cin,temp);
    fileout<<"Email:\t\t"<<temp<<"\n";
    cout<<"Experience(in Years): ";
    cin>>experience;
    cin.ignore();
    fileout<<"Experience:\t"<<experience<<"\n";
    cout<<"Summary: ";
    getline(cin,temp);
    fileout<<"Summary:\t"<<temp<<"\n";
    fileout.close();
//=======================================================================
    ifstream filein;
    filein.open("resume.txt");
    cout<<"\n==============Displaying Data from file==============="<<endl;
    if(filein.is_open()){
    while (getline(filein,temp)){
          cout <<temp<<endl;
    }
     filein.close();
    }
    else cout<<"Unable to open file"<<endl;

    return 0;
    
}