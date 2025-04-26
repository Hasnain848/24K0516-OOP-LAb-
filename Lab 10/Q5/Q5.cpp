/*Q5. You're building a tool to search and replace a specific word in a text file without
rewriting the entire file.
Requirements:

1. Create and populate a file named data.txt with a few sentences. (e.g., AI is the
future. AI will transform the world. Embrace AI now.)
2. Prompt the user to enter:
○ A searchWord (e.g., "AI")
○ A replacementWord (e.g., "ML")
3. Open the file using fstream in ios::in | ios::out mode.
4. Search for the searchWord using seekg() and read sequentially.
5. When found:
○ Use tellg() to get the current read pointer location.
○ Use seekp() to position the write pointer.
○ Replace the word only if the replacement is of equal or smaller length to
avoid shifting content.

6. If the word is replaced, pad with spaces if needed (e.g., replacing "AI" with "ML" or
"XX").
7. After all replacements, display the updated file.*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream file("data.txt",ios::out);
    if(!file.is_open())return 1;

    file <<"AI is the future. AI will transform the world. Embrace AI now.\n";

    if(file.is_open())file.close();

    fstream filedata("data.txt",ios::in | ios::out);
    if(!filedata.is_open()){
        cout<<"Error in opening";
        return 1;}
    string oldword,newword,word;
    cout<<"Enter the word to change: ";
    getline(cin,oldword);
    cout<<"Enter the New word: ";
    getline(cin,newword);

        if(newword.size()>oldword.size()){
            cout<<"You word is too long for concatenation";
            newword = newword.substr(0, oldword.length());
            //areturn 0;
        }
        else if(newword.size()<oldword.size()){
            int padding= oldword.size()-newword.size();
            newword.append(padding,'_');
        }
    streampos pos;
    bool flag =false;
    while(filedata >> word){
        pos = filedata.tellg();
        if(oldword==word){
            filedata.seekp(pos - static_cast<streamoff>(word.length()+1));
            filedata<<newword;
            flag=true;
            
        }
    }

    if(flag){
        cout<<"Word is updated:"<<endl;
        filedata.clear();            
        filedata.seekg(0, ios::beg);   
        string line;
        while (getline(filedata, line)) {
            cout << line << endl;
        }
    }
    
    else {
        cout<<"Soory Word not found"<<endl;
    }
    filedata.close();
    return 0 ;
}