/*Q4. You are testing how file pointers work in a file while reading and writing.
Requirements:
1. Write the sentence "C++ is a powerful programming language." to a file named
info.txt using ofstream in ios::out mode.
2. Reopen the file using fstream with both ios::in | ios::out modes.
3. Display the initial position of get pointer using tellg() and put pointer using tellp().
4. Use seekg(6) to move the read pointer to the word "powerful" and read the word
from there.
5. Use seekp(6) to move the write pointer to the same position, and overwrite
"powerful" with "dynamic" (same length).
6. Use tellg() and tellp() again to show the new pointer positions.
7. Display the updated content of the file.*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream file("info.txt",ios::out);
    if(!file.is_open())return 1;

    file <<"C++ is a powerful programming language.\n";

    if(file.is_open())file.close();

    fstream fileout("info.txt",ios::in | ios::out);
    if(!fileout.is_open())return 1;

    streampos pos1 = fileout.tellg();
    streampos pos2 = fileout.tellp();
    cout<<"Intial Positions"<<endl;
    cout<<"Getpointer: "<<pos1<<endl;
    cout<<"Putpointer: "<<pos2<<endl;

    fileout.seekg(9);
    string word;
    fileout>>word;
    cout<<"Word: "<<word<<endl;

    fileout.seekp(9);
    fileout.write("dynamic",8);

    cout<<"Modifyed Positions"<<endl;
    cout<<"Getpointer: "<<fileout.tellg()<<endl;
    cout<<"Putpointer: "<<fileout.tellp()<<endl;

    string line;
    fileout.seekg(0);
    while(getline(fileout,line))cout<<line<<endl;

    if(fileout.is_open()){
        fileout.close();
    }

}