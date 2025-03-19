#include<iostream>
using namespace std;

class Media{
    protected:
    string title,publictiondate,publisher;
    const int uniqueid;
    public:
    Media(string title,string publictiondate,string publisher,int id):
    title(title),publictiondate(publictiondate),uniqueid(id){}
    
};