#include <iostream>
using namespace std;

class Media
{
protected:
    string title, publictiondate, publisher;
    const int uniqueid;

public:
    Media(string title = "notitle", string publictiondate = "nodate", string publisher = "nopublisher", int id = 0) : title(title), publictiondate(publictiondate), uniqueid(id), publisher(publisher) {}
    virtual void displayinfo()
    {
        cout << " Media details" << endl;
        cout << "Title: " << title << endl;
        cout << "Publication date: " << publictiondate << endl;
        cout << "Id: " << uniqueid << endl;
        cout << "Publisher: " << publisher << endl;
    }
    void Checkout()
    {
        cout << "Checkout " << title << endl;
    }
    void returnitem()
    {
        cout << "Return: " << title << endl;
    }

    string gettitle() { return title; }
    string getpublicationdate() { return publictiondate; }
    string getpublisher() { return publisher; }
    int getid() { return uniqueid; }
};
class Book : public Media
{
    string author;
    int ISBN;
    int noPages;

public:
    Book(string title = "notitle", string publictiondate = "nodate", string publisher = "nopublisher", int id = 0, string author = "no author", int isbn = 0, int page = 0)
        : Media(title, publictiondate, publisher, id), author(author), ISBN(isbn), noPages(page) {}

    void displayinfo() override
    {
        Media::displayinfo();
        cout << "Author: " << author << endl;
        cout << "ISBN : " << ISBN << endl;
        cout << "Pages: " << noPages << endl;
    }

    string getauthor() { return author; }
    int getISBN() { return ISBN; }
};
class DVD : public Media
{
    string director;
    float duration;
    int rating;

public:
    DVD(string title = "notitle", string publictiondate = "nodate", string publisher = "nopublisher", int id = 0, string director = "nodirector", float duration = 0.0, int ratting = 0)
        : Media(title, publictiondate, publisher, id), director(director), duration(duration), rating(ratting) {}

    void displayinfo() override
    {
        Media::displayinfo();
        cout << "Director: " << director << endl;
        cout << "Duration : " << duration << endl;
        cout << "Rating: " << rating << endl;
    }
    string getdirector() { return director; }
};
class CD : public Media
{
    string artist;
    int noTracks;
    string genre;

public:
    CD(string title = "notitle", string publictiondate = "nodate", string publisher = "nopublisher", int id = 0, string artist = "noartist", int notracks = 0, string genre = "nogenre")
        : Media(title, publictiondate, publisher, id), artist(artist), noTracks(notracks), genre(genre) {}

    void displayinfo() override
    {
        Media::displayinfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks : " << noTracks << endl;
        cout << "Genre: " << genre << endl;
    }
    string getartist() { return artist; }
};
class Library
{
    Media **media;
    int size;

public:
    Library()
    {
        size = 0;
        media = new Media *[size];
    }
    void addmedia(Media *m)
    {
        Media **temp = new Media *[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = media[i];
        }
        temp[size] = m;
        delete[] media;
        media = temp;
        cout << "Media has been added" << endl;
        size++;
    }
    void searchtitle(string title)
    {
        for (int i = 0; i < size; i++)
        {
            if (media[i]->gettitle().find(title) != string::npos)
            {
                media[i]->displayinfo();
                return;
            }
        }
        cout << "Sorry no title found" << endl;
    }
    void searchdate(string date)
    {
        for (int i = 0; i < size; i++)
        {
            if (media[i]->getpublicationdate().find(date) != string::npos)
            {
                media[i]->displayinfo();
                return;
            }
        }
        cout << "Sorry no Date found" << endl;
    }
    ~Library()
    {
        for (int i = 0; i < size; i++)
        {
            delete media[i];
        }
        delete[] media;
    }
};
int main()
{
    Library lib;

    Media *b1 = new Book("C++ Primer", "2020-05-10", "Pearson", 101, "Stanley B. Lippman", 978032, 970);
    Media *b2 = new Book("Effective C++", "2019-08-15", "O'Reilly", 102, "Scott Meyers", 978032, 352);
    Media *d1 = new DVD("Inception", "2010-07-16", "Warner Bros", 201, "Christopher Nolan", 2.5, 9);
    Media *c1 = new CD("Thriller", "1982-11-30", "Epic Records", 301, "Michael Jackson", 9, "Pop");

    lib.addmedia(b1);
    lib.addmedia(b2);
    lib.addmedia(d1);
    lib.addmedia(c1);

    cout << "\nSearching for 'C++ Primer':\n";
    lib.searchtitle("C++ Primer");
    cout << "-----------------------------------------------------" << endl;
    cout << "\nSearching for '2010-07-16':\n";
    lib.searchdate("2010-07-16");

    return 0;
}
