#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
private:
    int id;
    std::string title;
    std::string author;

public:
    // Constructor to initialize book information
    Book(int bookId, std::string bookTitle, std::string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
    }

    // Getter methods for accessing private attributes
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }

    // Visual helper to format individual entries
    void displayBook() const {
        std::cout << "ID: " << id 
                  << " | Title: " << title 
                  << " | Author: " << author << "\n";
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    // Insert a new object into our memory container
    void addBook() {
        int id;
        std::string title, author;

        std::cout << "\nEnter Book ID (Integer): ";
        std::cin >> id;
        std::cin.ignore(); // Clean terminal stream buffer

        std::cout << "Enter Book Title: ";
        std::getline(std::cin, title);

        std::cout << "Enter Author Name: ";
        std::getline(std::cin, author);

        // Instantiating and pushing to list
        books.push_back(Book(id, title, author));
        std::cout << "Book successfully registered to catalog!\n";
    }

    // Display all items stored inside the structural vector
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "\nCatalog empty. No records found.\n";
            return;
        }
        std::cout << "\n--- Current Library Catalog ---\n";
        for (const auto& book : books) {
            book.displayBook();
        }
    }

    // Linearly scan and find specific details using IDs
    void searchBook() const {
        if (books.empty()) {
            std::cout << "\nCatalog empty. Searching disabled.\n";
            return;
        }

        int searchId;
        std::cout << "\nEnter Book ID to search: ";
        std::cin >> searchId;

        for (const auto& book : books) {
            if (book.getId() == searchId) {
                std::cout << "\nMatch Found:\n";
                book.displayBook();
                return;
            }
        }
        std::cout << "Error: Book with ID " << searchId << " not found.\n";
    }
};

int main() {
    Library myLibrary;
    int choice;

    do {
        std::cout << "\n===============================\n";
        std::cout << "     MINI LIBRARY SYSTEM       \n";
        std::cout << "===============================\n";
        std::cout << "1. Add New Book\n";
        std::cout << "2. Display All Books\n";
        std::cout << "3. Search Book by ID\n";
        std::cout << "4. Exit System\n";
        std::cout << "Enter option (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.displayAllBooks();
                break;
            case 3:
                myLibrary.searchBook();
                break;
            case 4:
                std::cout << "\nShutting down library systems. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid input. Please choose options 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}
