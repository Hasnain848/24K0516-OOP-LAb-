#include "Book.h"
#include <iostream>
using namespace std;
Book ::Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
string Book::gettitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getISBN() { return isbn; }
