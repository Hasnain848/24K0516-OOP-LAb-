/*Q3. You want to create a combined book by merging the contents of two chapters.
Requirements:
1. Assume two existing files: chapter1.txt and chapter2.txt. Populate them with some
text before running this.
2. Open chapter1.txt and chapter2.txt using ifstream in read mode.
3. Open book.txt using ofstream in ios::app mode.
4. Read from both files and append the contents sequentially to book.txt.
5. Ensure a newline is added between chapter contents.
6. After writing, open and display book.txt contents to verify concatenation.*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string line;
    ifstream chap1("chapter1.txt"),chap2("chapter2.txt");
    ofstream book("book.txt",ios::app);
    if(!chap1.is_open()){
        cout<<"Files not opened soory"<<endl;
        return 1;
    }
    if(!chap2.is_open()){
        cout<<"Files not opened soory"<<endl;
        return 1;
    }
    if(!book.is_open()){
        cout<<"Files not opened soory"<<endl;
        return 1;
    }
    while (getline(chap1,line)){
        book<<line;
    }

    book <<"\n\n";
    while (getline(chap2,line)){
        book<<line;
    }
    if(chap1.is_open()){
        chap1.close();
    }
    if(chap2.is_open()){
        chap2.close();
    }
    if(book.is_open()){
        book.close();
    }

    ifstream fileout("book.txt");
    cout<<"\nDisplaying Book content"<<endl;
    if(fileout.is_open()){
        while(getline(fileout,line)){
            cout<<line;
            cout<<endl;
        }
    }
    if(fileout.is_open()){
        fileout.close();
    }
}