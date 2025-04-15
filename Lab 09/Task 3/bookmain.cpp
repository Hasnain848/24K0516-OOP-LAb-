#include <iostream>
#include "Book.h"
using namespace std;
class Library
{
    Book **array;
    int bookcount, maxcount;

public:
    Library(int size)
    {
        bookcount = 0;
        maxcount = size;
        array = new Book *[maxcount];
    }
    void addBooks(Book *b)
    {
        if (bookcount > maxcount)
        {
            cout << "Soory library is full / out of space" << endl;
            return;
        }
        array[bookcount] = b;
        bookcount++;
        cout << "Book name: " << b->gettitle() << " has been added" << endl;
    }
    void removeBook(string title)
    {
        bool flag = false;
        for (int i = 0; i < bookcount; i++)
        {
            if (array[i]->gettitle() == title)
            {
                cout << "Book name:  " << array[i]->gettitle() << " has been removed" << endl;
                delete array[i];
                for (int j = i; j < bookcount; j++)
                {
                    array[j] = array[j + 1];
                }
                bookcount--;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "Sorry Book not Found" << endl;
        }
    }
    void searchBook(string title)
    {
        bool flag = false;
        for (int i = 0; i < bookcount; i++)
        {
            if (array[i]->gettitle() == title)
            {
                flag = true;
                cout << "Book Found Info is loading....." << endl;
                cout << "========== Book Details =============" << endl;
                cout << "Title: " << array[i]->gettitle() << endl;
                cout << "Author: " << array[i]->getAuthor() << endl;
                cout << "ISBN: " << array[i]->getISBN() << endl;
                cout << "=====================================" << endl;
                break;
            }
        }
        if (!flag)
        {
            cout << "Sorry Book not Found" << endl;
        }
    }

    ~Library()
    {
        for (int i = 0; i < bookcount; i++)
        {
            delete array[i];
        }
        delete[] array;
    }
};
int main()
{
    Library lib(5);

    Book *b1 = new Book("The Alchemist", "Paulo Coelho", "12345");
    Book *b2 = new Book("Clean Code", "Robert C. Martin", "67890");
    Book *b3 = new Book("C++ Primer", "Stanley B. Lippman", "54321");

    cout << "Book Meta data" << endl;
    cout << "Title: " << b1->gettitle() << endl;
    cout << "Author: " << b1->getAuthor() << endl;
    cout << "ISBN: " << b1->getISBN() << endl;
    cout << "---------------------------------------------" << endl;

    lib.addBooks(b1);
    lib.addBooks(b2);
    lib.addBooks(b3);

    cout << endl;

    lib.searchBook("Clean Code");

    cout << endl;

    lib.removeBook("The Alchemist");

    cout << endl;

    lib.searchBook("The Alchemist");

    cout << endl;
    return 0;
}
