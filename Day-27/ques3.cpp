#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class to manage individual employee data and salary calculations
class Employee {
private:
    int id;
    string name;
    string designation;
    double basicSalary;
    
    // Components computed automatically
    double allowanceHRA; // House Rent Allowance
    double allowanceDA;  // Dearness Allowance
    double taxDeduction; // Income Tax Deduction
    double netSalary;    // Final Take-Home Pay

public:
    // Constructor to initialize employee details
    Employee(int empId, string empName, string empDesg, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesg;
        basicSalary = empSalary;
        calculateSalary();
    }

    // Function to calculate salary components based on standard rules
    void calculateSalary() {
        allowanceHRA = 0.15 * basicSalary; // 15% of basic salary
        allowanceDA = 0.10 * basicSalary;  // 10% of basic salary
        
        double grossSalary = basicSalary + allowanceHRA + allowanceDA;
        
        // Progressive tax deduction rule
        if (grossSalary > 50000) {
            taxDeduction = 0.12 * grossSalary; // 12% tax for high earners
        } else if (grossSalary > 25000) {
            taxDeduction = 0.05 * grossSalary; // 5% tax
        } else {
            taxDeduction = 0.0;                 // No tax
        }
        
        netSalary = grossSalary - taxDeduction;
    }

    // Getter for Employee ID
    int getId() const { 
        return id; 
    }

    // Function to display short summary in a table row
    void displaySummary() const {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << setw(20) << designation 
             << "$" << fixed << setprecision(2) << netSalary << endl;
    }

    // Function to print a detailed, structured payslip
    void displayPayslip() const {
        cout << "\n=============================================\n";
        cout << "              EMPLOYEE PAYSLIP               \n";
        cout << "=============================================\n";
        cout << left << setw(20) << "Employee ID:" << id << "\n";
        cout << left << setw(20) << "Name:" << name << "\n";
        cout << left << setw(20) << "Designation:" << designation << "\n";
        cout << "---------------------------------------------\n";
        cout << left << setw(20) << "Basic Salary:" << "$" << basicSalary << "\n";
        cout << left << setw(20) << "HRA Allowance (+):" << "$" << allowanceHRA << "\n";
        cout << left << setw(20) << "DA Allowance (+):" << "$" << allowanceDA << "\n";
        cout << left << setw(20) << "Tax Deduction (-):" << "$" << taxDeduction << "\n";
        cout << "---------------------------------------------\n";
        cout << left << setw(20) << "NET TAKE-HOME PAY:" << "$" << netSalary << "\n";
        cout << "=============================================\n\n";
    }
};

// Main function managing the terminal-based menu loop
int main() {
    vector<Employee> database;
    int choice;

    // Default seed data for immediate testing
    database.push_back(Employee(101, "Alice Smith", "Software Engineer", 60000));
    database.push_back(Employee(102, "Bob Jones", "HR Manager", 45000));

    do {
        cout << "=== SALARY MANAGEMENT SYSTEM ===\n";
        cout << "1. Add New Employee Record\n";
        cout << "2. View All Employee Salaries\n";
        cout << "3. Generate Detailed Payslip\n";
        cout << "4. Exit Application\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name, desg;
                double salary;

                cout << "\nEnter Employee ID: ";
                cin >> id;
                cin.ignore(); // Clear buffer newline character
                cout << "Enter Full Name: ";
                getline(cin, name);
                cout << "Enter Designation: ";
                getline(cin, desg);
                cout << "Enter Base Salary ($): ";
                cin >> salary;

                database.push_back(Employee(id, name, desg, salary));
                cout << "\n✔ Employee record saved successfully!\n\n";
                break;
            }
            case 2: {
                if (database.empty()) {
                    cout << "\n⚠ No records found.\n\n";
                    break;
                }
                cout << "\n-------------------------------------------------------------\n";
                cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Designation" << "Net Salary\n";
                cout << "-------------------------------------------------------------\n";
                for (const auto& emp : database) {
                    emp.displaySummary();
                }
                cout << "-------------------------------------------------------------\n\n";
                break;
            }
            case 3: {
                if (database.empty()) {
                    cout << "\n⚠ No employee records available.\n\n";
                    break;
                }
                int searchId;
                bool found = false;
                cout << "\nEnter Employee ID to generate payslip: ";
                cin >> searchId;

                for (const auto& emp : database) {
                    if (emp.getId() == searchId) {
                        emp.displayPayslip();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\n❌ Error: Employee ID not found.\n\n";
                }
                break;
            }
            case 4:
                cout << "\nExiting execution window. Goodbye!\n";
                break;
            default:
                cout << "\n❌ Invalid choice! Please select a valid menu option.\n\n";
        }
    } while (choice != 4);

    return 0;
}
