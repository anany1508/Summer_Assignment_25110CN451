#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;
    int id;

public:
    Person(string n, int a, int i) : name(n), age(a), id(i) {}
    virtual ~Person() {}

    int getId() const { return id; }
    
    // Pure virtual functions for Polymorphism
    virtual void displayDetails() const = 0;
    virtual string getType() const = 0;
};

// Derived Class for Students
class Student : public Person {
private:
    string course;
    double gpa;

public:
    Student(string n, int a, int i, string c, double g) 
        : Person(n, a, i), course(c), gpa(g) {}

    string getType() const override { return "Student"; }

    void displayDetails() const override {
        cout << "| " << setw(6) << id 
             << "| " << setw(12) << name 
             << "| " << setw(5) << age 
             << "| " << setw(10) << "Student" 
             << "| Course: " << setw(10) << course 
             << " | Performance: " << gpa << " GPA |" << endl;
    }
};

// Derived Class for Employees
class Employee : public Person {
private:
    string department;
    double salary;

public:
    Employee(string n, int a, int i, string dept, double sal) 
        : Person(n, a, i), department(dept), salary(sal) {}

    string getType() const override { return "Employee"; }

    void displayDetails() const override {
        cout << "| " << setw(6) << id 
             << "| " << setw(12) << name 
             << "| " << setw(5) << age 
             << "| " << setw(10) << "Employee" 
             << "| Dept: " << setw(12) << department 
             << " | Salary: $" << setw(8) << fixed << setprecision(2) << salary << " |" << endl;
    }
};

// Management System Class
class ManagementSystem {
private:
    vector<unique_ptr<Person>> records;

public:
    void addStudent() {
        string name, course;
        int age, id;
        double gpa;

        cout << "\n--- Add Student Record ---\n";
        cout << "Enter ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Age: "; cin >> age;
        cin.ignore();
        cout << "Enter Course: "; getline(cin, course);
        cout << "Enter GPA: "; cin >> gpa;

        records.push_back(make_unique<Student>(name, age, id, course, gpa));
        cout << "Student record added successfully!\n";
    }

    void addEmployee() {
        string name, department;
        int age, id;
        double salary;

        cout << "\n--- Add Employee Record ---\n";
        cout << "Enter ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Age: "; cin >> age;
        cin.ignore();
        cout << "Enter Department: "; getline(cin, department);
        cout << "Enter Salary: "; cin >> salary;

        records.push_back(make_unique<Employee>(name, age, id, department, salary));
        cout << "Employee record added successfully!\n";
    }

    void displayAll() const {
        if (records.empty()) {
            cout << "\nNo records found in the database.\n";
            return;
        }
        cout << "\n" << string(75, '=') << "\n";
        cout << "| " << setw(6) << "ID" 
             << "| " << setw(12) << "Name" 
             << "| " << setw(5) << "Age" 
             << "| " << setw(10) << "Role" 
             << "| Additional Info " << "\n";
        cout << string(75, '-') << "\n";
        for (const auto& person : records) {
            person->displayDetails();
        }
        cout << string(75, '=') << "\n";
    }

    void searchRecord() const {
        int searchId;
        cout << "\nEnter ID to search: ";
        cin >> searchId;

        for (const auto& person : records) {
            if (person->getId() == searchId) {
                cout << "\nRecord Found:\n";
                person->displayDetails();
                return;
            }
        }
        cout << "Record with ID " << searchId << " not found.\n";
    }

    void deleteRecord() {
        int deleteId;
        cout << "\nEnter ID to delete: ";
        cin >> deleteId;

        for (auto it = records.begin(); it != records.end(); ++it) {
            if ((*it)->getId() == deleteId) {
                cout << "Removing " << (*it)->getType() << ": " << (*it)->getId() << "...\n";
                records.erase(it);
                cout << "Record deleted successfully.\n";
                return;
            }
        }
        cout << "Record with ID " << deleteId << " not found.\n";
    }
};

int main() {
    ManagementSystem system;
    int choice;

    do {
        cout << "\n=== Student & Employee Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Add Employee\n";
        cout << "3. Display All Records\n";
        cout << "4. Search Record by ID\n";
        cout << "5. Delete Record by ID\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: system.addStudent(); break;
            case 2: system.addEmployee(); break;
            case 3: system.displayAll(); break;
            case 4: system.searchRecord(); break;
            case 5: system.deleteRecord(); break;
            case 6: cout << "Exiting system. Goodbye!\n"; break;
            default: cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
