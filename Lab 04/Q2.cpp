#include <iostream>
using namespace std;

class Book {
    int id;
    string title;
    string author;
    bool available;

public:
    // Constructor Overloading
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->available = true;
    }

    Book(int id, string title, string author, bool available) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->available = available;
    }

    void displayBookDetails() {
        cout << "ID: " << id << "\n Title: " << title << "\n Author: " << author
             << "\n Availability: " << (available ? "Available" : "Not Available") << endl;
    }

   
    int getId() { return id; }
    bool isAvailable() { return available; }

  
    void setAvailable(bool available) { this->available = available; }
};

class Library {
    Book** books; 
    int capacity;
    int numBooks;

public:
    Library(int capacity) {
        this->capacity = capacity;
        this->numBooks = 0;
        this->books = new Book*[capacity]; 
    }

    ~Library() {
        for (int i = 0; i < numBooks; i++) {
            delete books[i];
        }
        delete[] books; 
    }

    void addBook(int id, string title, string author) {
        if (numBooks < capacity) {
            books[numBooks++] = new Book(id, title, author);
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    void borrowBook(int id) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i]->getId() == id && books[i]->isAvailable()) {
                books[i]->setAvailable(false);
                cout << "Book with ID " << id << " borrowed successfully!" << endl;
                return;
            }
        }
        cout << "Book with ID " << id << " is not available or does not exist." << endl;
    }

    void returnBook(int id) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i]->getId() == id && !books[i]->isAvailable()) {
                books[i]->setAvailable(true);
                cout << "Book with ID " << id << " returned successfully!" << endl;
                return;
            }
        }
        cout << "Book with ID " << id << " is not available or does not exist." << endl;
    }

    void displayAllBooks() {
        cout << "--------------All Books in Library:-----------" << endl;
        for (int i = 0; i < numBooks; i++) {
            books[i]->displayBookDetails();
        }
        cout<<"-----------------------------------------------------" << endl;
    }
};

int main() {
    Library library(5);

    library.addBook(1, "To Kill a Mockingbird", "Harper Lee");
    library.addBook(2, "1984", "George Orwell");
    library.addBook(3, "The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook(4, "The Catcher in the Rye", "J.D. Salinger");

    library.displayAllBooks();

    library.borrowBook(2);
    library.borrowBook(10);

    library.returnBook(2);

    library.displayAllBooks();

    return 0;
}
