#include<iostream>
//#include<exception>
using namespace std;
class FileException{
    public:
    virtual const char* what(){
        return "FileException occurred";
    }
};
class FileNotFound : public FileException{
    public:
    const char* what()override{
    return("File not Exception");
    }
};
class PermissionDenied : public FileException{
    public:
    const char* what()override{
    return("Permission denied exception - Access Denied");
    }
};
void read(const string &filename){
    if(filename == "missing.txt")
        throw FileNotFound();
    else if(filename =="secret.txt")
        throw PermissionDenied();
    else  cout << "Reading '" << filename << "': File read successfully!" << endl;
}
int main(){
    string files[3]={"secret.txt","missing.txt","example.txt"};
    for (int i=0;i<3;i++){
        try{
            read(files[i]);
        }
             catch (const FileNotFoundException& e) {
            cout << "Reading '" << file << "': " << e.what() << endl;
        }
        catch (const PermissionDeniedException& e) {
            cout << "Reading '" << file << "': " << e.what() << endl;
        }
        catch (const FileException& e) {
            cout << "Reading '" << file << "': " << e.what() << endl;
        }
}
