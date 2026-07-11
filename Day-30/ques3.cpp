#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Class representing an individual Employee
class Employee {
private:
    int id;
    string name;
    string designation;
    double salary;

public:
    // Constructor
    Employee(int empId, string empName, string empDesig, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesig;
        salary = empSalary;
    }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getDesignation() const { return designation; }
    double getSalary() const { return salary; }

    // Setters for updating records
    void setName(string empName) { name = empName; }
    void setDesignation(string empDesig) { designation = empDesig; }
    void setSalary(double empSalary) { salary = empSalary; }

    // Display employee data in a clean row format
    void displayRow() const {
        cout << left << setw(10) << id 
             << setw(25) << name 
             << setw(20) << designation 
             << "$" << fixed << setprecision(2) << salary << endl;
    }
};

// Class handling system management operations
class ManagementSystem {
private:
    vector<Employee> employees;

    // Helper method to look up employee index by ID
    int findEmployeeIndex(int id) {
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].getId() == id) {
                return i;
            }
        }
        return -1; // Not found
    }

public:
    // 1. Add a new employee record
    void addEmployee() {
        int id;
        string name, designation;
        double salary;

        cout << "\n--- Add New Employee ---\n";
        cout << "Enter Employee ID (Numeric): ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter a numeric ID: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (findEmployeeIndex(id) != -1) {
            cout << "Error: Employee with ID " << id << " already exists!\n";
            return;
        }

        cin.ignore(); // Clear buffer
        cout << "Enter Full Name: ";
        getline(cin, name);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Salary: ";
        while (!(cin >> salary) || salary < 0) {
            cout << "Invalid input. Enter a valid positive salary: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        employees.push_back(Employee(id, name, designation, salary));
        cout << "Employee record added successfully!\n";
    }

    // 2. Display all active employees
    void displayAllEmployees() {
        if (employees.empty()) {
            cout << "\nNo employee records found in the system.\n";
            return;
        }

        cout << "\n------------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
        cout << "------------------------------------------------------------------\n";
        for (const auto& emp : employees) {
            emp.displayRow();
        }
        cout << "------------------------------------------------------------------\n";
    }

    // 3. Search employee by ID
    void searchEmployee() {
        if (employees.empty()) {
            cout << "\nDatabase is empty.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to Search: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            cout << "\n--- Match Found ---\n";
            cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
            cout << "------------------------------------------------------------------\n";
            employees[index].displayRow();
        } else {
            cout << "Employee record with ID " << id << " not found.\n";
        }
    }

    // 4. Update an existing employee record
    void updateEmployee() {
        if (employees.empty()) {
            cout << "\nDatabase is empty.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to Update: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index == -1) {
            cout << "Employee record with ID " << id << " not found.\n";
            return;
        }

        string name, designation;
        double salary;

        cin.ignore();
        cout << "Enter New Name (Current: " << employees[index].getName() << "): ";
        getline(cin, name);
        cout << "Enter New Designation (Current: " << employees[index].getDesignation() << "): ";
        getline(cin, designation);
        cout << "Enter New Salary (Current: $" << employees[index].getSalary() << "): ";
        while (!(cin >> salary) || salary < 0) {
            cout << "Invalid input. Enter a valid positive salary: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        employees[index].setName(name);
        employees[index].setDesignation(designation);
        employees[index].setSalary(salary);

        cout << "Employee record updated successfully!\n";
    }

    // 5. Delete an employee record
    void deleteEmployee() {
        if (employees.empty()) {
            cout << "\nDatabase is empty.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to Delete: ";
        cin >> id;

        int index = findEmployeeIndex(id);
        if (index != -1) {
            employees.erase(employees.begin() + index);
            cout << "Employee record deleted successfully!\n";
        } else {
            cout << "Employee record with ID " << id << " not found.\n";
        }
    }
};

// Main execution loop
int main() {
    ManagementSystem system;
    int choice;

    do {
        cout << "\n===== MINI EMPLOYEE MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Update Employee Record\n";
        cout << "5. Delete Employee Record\n";
        cout << "6. Exit\n";
        cout << "===========================================\n";
        cout << "Enter your choice (1-6): ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: system.addEmployee(); break;
            case 2: system.displayAllEmployees(); break;
            case 3: system.searchEmployee(); break;
            case 4: system.updateEmployee(); break;
            case 5: system.deleteEmployee(); break;
            case 6: cout << "\nExiting System. Goodbye!\n"; break;
            default: cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
