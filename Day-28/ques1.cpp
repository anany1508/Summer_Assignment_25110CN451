#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Class representing an individual Book
class Book {
private:
    int id;
    string title;
    string author;
    int quantity;

public:
    // Constructor to initialize book details
    Book(int bId, string bTitle, string bAuthor, int bQty) {
        id = bId;
        title = bTitle;
        author = bAuthor;
        quantity = bQty;
    }

    // Getter methods
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getQuantity() const { return quantity; }

    // Method to update inventory quantity
    void updateQuantity(int amount) {
        quantity += amount;
    }

    // Method to display book info in a row format
    void displayRow() const {
        cout << left << setw(10) << id 
             << setw(30) << title 
             << setw(25) << author 
             << setw(10) << quantity << endl;
    }
};

// Class handling the Library operations
class Library {
private:
    vector<Book> books;

public:
    // 1. Add a new book or update quantity if it already exists
    void addBook() {
        int id, qty;
        string title, author;

        cout << "\nEnter Book ID (Integer): ";
        while (!(cin >> id)) {
            cout << "Invalid input! Enter an integer for ID: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore(); // Clear newline buffer

        // Check if book already exists
        for (auto &book : books) {
            if (book.getId() == id) {
                cout << "Book ID already exists! Enter additional quantity to add: ";
                cin >> qty;
                book.updateQuantity(qty);
                cout << "Quantity updated successfully!\n";
                return;
            }
        }

        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Quantity: ";
        while (!(cin >> qty) || qty < 0) {
            cout << "Invalid quantity! Enter a positive integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        books.push_back(Book(id, title, author, qty));
        cout << "Book added successfully!\n";
    }

    // 2. Display all books currently in the library
    void displayBooks() const {
        if (books.empty()) {
            cout << "\nThe library inventory is empty.\n";
            return;
        }

        cout << "\n----------------------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(25) << "Author" << setw(10) << "Quantity" << endl;
        cout << "----------------------------------------------------------------------------\n";
        for (const auto &book : books) {
            book.displayRow();
        }
        cout << "----------------------------------------------------------------------------\n";
    }

    // 3. Search for a book by its Unique ID
    void searchBook() const {
        if (books.empty()) {
            cout << "\nNo books available to search.\n";
            return;
        }

        int searchId;
        cout << "\nEnter Book ID to search: ";
        cin >> searchId;

        for (const auto &book : books) {
            if (book.getId() == searchId) {
                cout << "\nBook Found:\n";
                cout << "-------------------------------------\n";
                cout << "ID: " << book.getId() << "\n";
                cout << "Title: " << book.getTitle() << "\n";
                cout << "Author: " << book.getAuthor() << "\n";
                cout << "Available Copies: " << book.getQuantity() << "\n";
                cout << "-------------------------------------\n";
                return;
            }
        }
        cout << "Book with ID " << searchId << " not found.\n";
    }

    // 4. Delete a book completely from the database
    void deleteBook() {
        if (books.empty()) {
            cout << "\nNo books available to delete.\n";
            return;
        }

        int deleteId;
        cout << "\nEnter Book ID to remove: ";
        cin >> deleteId;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == deleteId) {
                books.erase(it);
                cout << "Book removed from library successfully!\n";
                return;
            }
        }
        cout << "Book with ID " << deleteId << " not found.\n";
    }
};

int main() {
    Library myLibrary;
    int choice;

    while (true) {
        cout << "\n=========================================\n";
        cout << "        LIBRARY MANAGEMENT SYSTEM        \n";
        cout << "=========================================\n";
        cout << "1. Add / Restock Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Delete Book Record\n";
        cout << "5. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice (1-5): ";
        
        if (!(cin >> choice)) {
            cout << "Invalid option! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.displayBooks();
                break;
            case 3:
                myLibrary.searchBook();
                break;
            case 4:
                myLibrary.deleteBook();
                break;
            case 5:
                cout << "\nThank you for using the Library Management System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please select a valid option from the menu.\n";
        }
    }
    return 0;
}
