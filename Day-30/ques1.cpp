#include <iostream>
#include <string>

using namespace std;

// Maximum capacity of the student database
const int MAX_STUDENTS = 100;

// Parallel arrays to store student data
string studentNames[MAX_STUDENTS];
int rollNumbers[MAX_STUDENTS];
double studentMarks[MAX_STUDENTS];

// Counter to track the actual number of registered students
int currentStudentCount = 0;

// Function prototypes
void displayMenu();
void addStudentRecord();
void displayAllRecords();
void searchStudentRecord();

int main() {
    int userChoice;

    do {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        cin >> userChoice;

        // Clear the input buffer to handle potential formatting mismatches
        cin.ignore();

        switch (userChoice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                searchStudentRecord();
                break;
            case 4:
                cout << "\nExiting the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid selection! Please enter a number between 1 and 4.\n";
        }
    } while (userChoice != 4);

    return 0;
}

// Displays the interactive CLI menu
void displayMenu() {
    cout << "\n=================================";
    cout << "\n     STUDENT RECORD SYSTEM       ";
    cout << "\n=================================";
    cout << "\n1. Add a New Student Record";
    cout << "\n2. Display All Student Records";
    cout << "\n3. Search Student by Roll Number";
    cout << "\n4. Exit Program";
    cout << "\n=================================\n";
}

// Adds a student's information to the parallel arrays
void addStudentRecord() {
    if (currentStudentCount >= MAX_STUDENTS) {
        cout << "\nError: The student database is fully loaded!\n";
        return;
    }

    cout << "\n--- Add New Student Record ---" << endl;
    
    cout << "Enter Full Name: ";
    getline(cin, studentNames[currentStudentCount]);

    cout << "Enter Roll Number: ";
    cin >> rollNumbers[currentStudentCount];

    cout << "Enter Marks: ";
    cin >> studentMarks[currentStudentCount];

    currentStudentCount++;
    cout << "\nSuccess: Record added successfully!\n";
}

// Iterates through the database and displays all registered entries
void displayAllRecords() {
    if (currentStudentCount == 0) {
        cout << "\nNotice: No student records found in the system.\n";
        return;
    }

    cout << "\n--- All Student Records ---" << endl;
    for (int i = 0; i < currentStudentCount; i++) {
        cout << "ID: " << (i + 1) 
             << " | Name: " << studentNames[i] 
             << " | Roll No: " << rollNumbers[i] 
             << " | Marks: " << studentMarks[i] << endl;
    }
}

// Searches for a record sequentially using a Roll Number
void searchStudentRecord() {
    if (currentStudentCount == 0) {
        cout << "\nNotice: The database is currently empty.\n";
        return;
    }

    int searchRoll;
    bool matchFound = false;

    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    for (int i = 0; i < currentStudentCount; i++) {
        if (rollNumbers[i] == searchRoll) {
            cout << "\n--- Record Located ---" << endl;
            cout << "Name: " << studentNames[i] << endl;
            cout << "Roll Number: " << rollNumbers[i] << endl;
            cout << "Marks Obtained: " << studentMarks[i] << endl;
            matchFound = true;
            break; 
        }
    }

    if (!matchFound) {
        cout << "\nResult: No student found matching Roll Number " << searchRoll << ".\n";
    }
}
