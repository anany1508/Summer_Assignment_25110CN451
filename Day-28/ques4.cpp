#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Class representing a single contact entity
class Contact {
private:
    string name;
    string phone;
    string email;

public:
    // Constructor
    Contact(string n, string p, string e) : name(n), phone(p), email(e) {}

    // Getters
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }

    // Setters
    void setName(const string& n) { name = n; }
    void setPhone(const string& p) { phone = p; }
    void setEmail(const string& e) { email = e; }

    // Method to display contact details in a row format
    void displayContactRow(int index) const {
        cout << left << setw(8) << index 
             << setw(25) << name 
             << setw(18) << phone 
             << setw(30) << email << endl;
    }
};

// Class handling CRUD operations for contacts
class ContactManager {
private:
    vector<Contact> contacts;

    // Helper utility to convert a string to lowercase for case-insensitive searching
    string toLower(string str) const {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

public:
    // 1. Add a new contact
    void addContact() {
        string name, phone, email;
        cin.ignore(); // Clear buffer
        
        cout << "\nEnter Name: ";
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Email Address: ";
        getline(cin, email);

        contacts.push_back(Contact(name, phone, email));
        cout << "\n[Success] Contact added successfully!\n";
    }

    // 2. Display all saved contacts
    void displayAllContacts() const {
        if (contacts.empty()) {
            cout << "\n[Info] No contacts available.\n";
            return;
        }

        printHeader();
        for (size_t i = 0; i < contacts.size(); ++i) {
            contacts[i].displayContactRow(i + 1);
        }
        printFooter();
    }

    // 3. Search contact by name
    void searchContact() const {
        if (contacts.empty()) {
            cout << "\n[Info] Contact list is empty.\n";
            return;
        }

        string query;
        cin.ignore();
        cout << "\nEnter name to search: ";
        getline(cin, query);

        string lowerQuery = toLower(query);
        bool found = false;

        printHeader();
        for (size_t i = 0; i < contacts.size(); ++i) {
            if (toLower(contacts[i].getName()).find(lowerQuery) != string::npos) {
                contacts[i].displayContactRow(i + 1);
                found = true;
            }
        }
        printFooter();

        if (!found) {
            cout << "[Info] No matching contacts found.\n";
        }
    }

    // 4. Update an existing contact
    void editContact() {
        if (contacts.empty()) {
            cout << "\n[Info] No contacts available to edit.\n";
            return;
        }

        int index;
        displayAllContacts();
        cout << "Enter the Serial Number of the contact you want to edit: ";
        cin >> index;

        if (index < 1 || index > static_cast<int>(contacts.size())) {
            cout << "\n[Error] Invalid Serial Number!\n";
            return;
        }

        // Adjust for 0-indexed vector array
        Contact& contact = contacts[index - 1]; 
        string input;
        cin.ignore();

        cout << "\nLeave field blank and press Enter to keep the existing value.\n";

        cout << "Current Name (" << contact.getName() << "): ";
        getline(cin, input);
        if (!input.empty()) contact.setName(input);

        cout << "Current Phone (" << contact.getPhone() << "): ";
        getline(cin, input);
        if (!input.empty()) contact.setPhone(input);

        cout << "Current Email (" << contact.getEmail() << "): ";
        getline(cin, input);
        if (!input.empty()) contact.setEmail(input);

        cout << "\n[Success] Contact updated successfully!\n";
    }

    // 5. Remove a contact
    void deleteContact() {
        if (contacts.empty()) {
            cout << "\n[Info] No contacts available to delete.\n";
            return;
        }

        int index;
        displayAllContacts();
        cout << "Enter the Serial Number of the contact you want to delete: ";
        cin >> index;

        if (index < 1 || index > static_cast<int>(contacts.size())) {
            cout << "\n[Error] Invalid Serial Number!\n";
            return;
        }

        contacts.erase(contacts.begin() + (index - 1));
        cout << "\n[Success] Contact deleted successfully!\n";
    }

private:
    // Visual interface helpers
    void printHeader() const {
        cout << "\n" << string(81, '-') << "\n";
        cout << left << setw(8) << "S.No" 
             << setw(25) << "Name" 
             << setw(18) << "Phone" 
             << setw(30) << "Email" << endl;
        cout << string(81, '-') << "\n";
    }

    void printFooter() const {
        cout << string(81, '-') << "\n\n";
    }
};

// Driver main loop interface 
int main() {
    ContactManager manager;
    int choice;

    do {
        cout << "=================================\n";
        cout << "    CONTACT MANAGEMENT SYSTEM    \n";
        cout << "=================================\n";
        cout << "1. Add New Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Edit Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Error checking for non-integer choices
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "\n[Error] Invalid input. Please enter a valid number.\n\n";
            continue;
        }

        switch (choice) {
            case 1: manager.addContact(); break;
            case 2: manager.displayAllContacts(); break;
            case 3: manager.searchContact(); break;
            case 4: manager.editContact(); break;
            case 5: manager.deleteContact(); break;
            case 6: cout << "\nThank you for using the Contact Management System!\n"; break;
            default: cout << "\n[Error] Choice out of bounds. Try 1 to 6.\n\n";
        }
    } while (choice != 6);

    return 0;
}
