#include<iostream>
//#include<exception>
using namespace std;
class FileException{
    public:
    virtual const char* what()=0;
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