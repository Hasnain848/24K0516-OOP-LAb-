#include<iostream>
#include "Book.h"
using namespace std;

int main() {
    string s,s2;
    Book b("test","tset","tes");
   s= b.getAuthor();
   s2= b.getISBN();
   return 0;
   
}