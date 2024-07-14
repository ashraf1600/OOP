#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Media {
public:
    T Title;
    T Author;
    T ReleaseYear;
};
class Book : public Media<string>
{
    public:
    string Publisher;
};

class CD : public Media<string>
{
public:
    string Artist;
};

class DVD : public Media<string> {
public:
    string Director;
};

class Inventory
{
public:
    vector<Book> Books;
    vector<CD> CDs;
    vector<DVD> DVDs;

    void BookAdd(const Book& book)
    {
        Books.push_back(book);
    }

    void CDAdd(const CD& cd)
    {
        CDs.push_back(cd);
    }

    void DVDAdd(const DVD& dvd)
    {
        DVDs.push_back(dvd);
    }

    void BookRemove(const string& title)
    {
        Books.erase(remove_if(Books.begin(), Books.end(), [&](Book& b) { return b.Title == title; }), Books.end());
    }

    void CDRemove(const string& title) {
        CDs.erase(remove_if(CDs.begin(), CDs.end(), [&](CD& c) { return c.Title == title; }), CDs.end());
    }

    void DVDRemove(const string& title) {
        DVDs.erase(remove_if(DVDs.begin(), DVDs.end(), [&](DVD& d) { return d.Title == title; }), DVDs.end());
    }

    void BookUpdate(const string& title, const Book& Bookupdate)
    {
        auto it = find_if(Books.begin(), Books.end(), [&](Book& b) { return b.Title == title; });
        if (it != Books.end())
		{
            it->Title = Bookupdate.Title;
            it->Author = Bookupdate.Author;
            it->ReleaseYear = Bookupdate.ReleaseYear;
            it->Publisher = Bookupdate.Publisher;
        }
    }

    void CDUpdate(const string& title, const CD& Cdupdate)
    {
        auto it = find_if(CDs.begin(), CDs.end(), [&](CD& c) { return c.Title == title; });
        if (it != CDs.end()) {
            it->Title = Cdupdate.Title;
            it->Artist = Cdupdate.Artist;
            it->ReleaseYear = Cdupdate.ReleaseYear;
        }
    }

    void DVDUpdate(const string& title, const DVD& Dvdupdate)
    {
        auto it = find_if(DVDs.begin(), DVDs.end(), [&](DVD& d) { return d.Title == title; });
        if (it != DVDs.end())
		{
            it->Title = Dvdupdate.Title;
            it->Director = Dvdupdate.Director;
            it->ReleaseYear = Dvdupdate.ReleaseYear;
        }
    }
};

int main() {
    Inventory inventory;
    int input;
    string title;

    Book b;
    b.Title = "Kuhelika"; b.Author = "Kazi Nazrul Islam"; b.Publisher = "Alok"; b.ReleaseYear = "1991"; inventory.BookAdd(b);
    Book b1;
    b1.Title = "Bisher bashi"; b1.Author = "Kazi Nazrul Islam"; b1.Publisher = "alok"; b1.ReleaseYear = "1991"; inventory.BookAdd(b1);

    CD c;
    CD c1;
    c.Title = "Hamnadh"; c.Author = "Islamic Foundation"; c.Artist = "Wali Ullah"; c.ReleaseYear = "2018"; inventory.CDAdd(c);
    c1.Title = "Deshattokbodhok song "; c1.Author = "Bangla Academy"; c1.Artist = "Unknown"; c1.ReleaseYear = "2007"; inventory.CDAdd(c1);

    DVD d;
    d.Title = "C Programming"; d.Author = "Shuvin"; d.Director = "Ali Faiyaz"; d.ReleaseYear = "2019"; inventory.DVDAdd(d);
    DVD d1;
    d1.Title = "C++ Programming"; d1.Author = "Shuvin"; d1.Director = "Ashraf"; d1.ReleaseYear = "2012"; inventory.DVDAdd(d1);

    while (true) {
        // Instruction for users
        cout << "Press 1 to 7 to select any choice" << endl;
        cout << "1. BOOK" << endl;
        cout << "2. CD" << endl;
        cout << "3. DVD" << endl;
        cout << "4. Book Details" << endl;
        cout << "5. CD Details" << endl;
        cout << "6. DVD Details" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> input;

        if (input == 1) { // for book segment
            cout << "\n[Book Segment]" << endl;
            while (true) {
                Book book;
                cout << "Select any option to perform operations below\n";
                cout << "1. Add a Book\n2. Update a Book\n3. Remove a Book\n4. Go Back" << endl;
                cin >> input;

                if (input == 4)
                    break;

                if (input == 1) {
                    cout << "Give the Book Title: ";
                    cin >> book.Title;
                    cout << "Enter the author name of the book: ";
                    cin >> book.Author;
                    cout << "Enter the publish date of the book: ";
                    cin >> book.ReleaseYear;
                    cout << "Enter the Publisher of the book: ";
                    cin >> book.Publisher;
                    inventory.BookAdd(book);
                } else if (input == 2) {
                    cout << "Input the Title of the Book to Update: ";
                    cin >> title;
                    Book Bookup;
                    cout << "Enter the Updated Book Title: ";
                    cin >> Bookup.Title;
                    cout << "Enter the Updated Book Author Name: ";
                    cin >> Bookup.Author;
                    cout << "Enter the Updated Book Publish Date: ";
                    cin >> Bookup.ReleaseYear;
                    cout << "Enter the Updated Publisher: ";
                    cin >> Bookup.Publisher;
                    inventory.BookUpdate(title, Bookup);
                } else if (input == 3) {
                    cout << "Input the Title of the Book to Remove: ";
                    cin >> title;
                    inventory.BookRemove(title);
                }
            }
        } else if (input == 2) { // for CD segment
            cout << "\n[CD Segment]" << endl;
            while (true) {
                CD cd;
                cout << "Select any option to perform operations below\n";
                cout << "1. Add a CD\n2. Update a CD\n3. Remove a CD\n4. Go Back" << endl;
                cin >> input;

                if (input == 4)
                    break;

                if (input == 1) {
                    cout << "Give the CD Title: ";
                    cin >> cd.Title;
                    cout << "Enter the CD Artist: ";
                    cin >> cd.Artist;
                    cout << "Enter the CD Release year: ";
                    cin >> cd.ReleaseYear;
                    inventory.CDAdd(cd);
                } else if (input == 2) {
                    cout << "Input the Title of the CD to Update: ";
                    cin >> title;
                    CD cdup;
                    cout << "Enter the Updated CD Title: ";
                    cin >> cdup.Title;
                    cout << "Enter the Updated CD Artist: ";
                    cin >> cdup.Artist;
                    cout << "Enter the Updated CD Release Year: ";
                    cin >> cdup.ReleaseYear;
                    inventory.CDUpdate(title, cdup);
                } else if (input == 3) {
                    cout << "Enter the Title of the CD to Remove: ";
                    cin >> title;
                    inventory.CDRemove(title);
                }
            }
        } else if (input == 3) { // for DVD segment
            cout << "\n[DVD Segment]" << endl;
            while (true) {
                DVD dvd;
                cout << "Select any option to perform operations below\n";
                cout << "1. Add a DVD\n2. Update a DVD\n3. Remove a DVD\n4. Go Back" << endl;
                cin >> input;

                if (input == 4)
                    break;

                if (input == 1) {
                    cout << "Give the DVD Title: ";
                    cin >> dvd.Title;
                    cout << "Enter the name of the DVD Director: ";
                    cin >> dvd.Director;
                    cout << "Enter the DVD Release Year: ";
                    cin >> dvd.ReleaseYear;
                    inventory.DVDAdd(dvd);
                } else if (input == 2) {
                    cout << "Give the Title of the DVD to Update: ";
                    cin >> title;
                    DVD dvdup;
                    cout << "Enter the Updated DVD Title: ";
                    cin >> dvdup.Title;
                    cout << "Enter the Updated DVD Director name: ";
                    cin >> dvdup.Director;
                    cout << "Enter the Updated DVD Release Year: ";
                    cin >> dvdup.ReleaseYear;
                    inventory.DVDUpdate(title, dvdup);
                } else if (input == 3) {
                    cout << "Input the Title of the DVD to Remove: ";
                    cin >> title;
                    inventory.DVDRemove(title);
                }
            }
        } else if (input == 4) { // to show book details
            cout << "\nAll Books are below :" << endl;
            for (const auto& book : inventory.Books)
                cout << book.Author << " - " << book.Title << " (" << book.ReleaseYear << ")" << endl;
        } else if (input == 5) { // to show CD details
            cout << "All CDs are below:" << endl;
            for (const auto& cd : inventory.CDs)
                cout << cd.Artist << " - " << cd.Title << " (" << cd.ReleaseYear << ")" << endl;
        } else if (input == 6) { // to show DVD details
            cout << "\nAll DVDs are below :" << endl;
            for (const auto& dvd : inventory.DVDs)
                cout << dvd.Director << " - " << dvd.Title << " (" << dvd.ReleaseYear << ")" << endl;
        } else if (input == 7) { // Exit condition
            break;
        }
    }
    return 0;
}

