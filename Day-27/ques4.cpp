#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to store subject details
struct Subject {
    string name;
    int maxMarks;
    int obtainedMarks;
};

// Class to handle Student data and processing
class Student {
private:
    string name;
    int rollNumber;
    vector<Subject> subjects;
    int totalMaxMarks;
    int totalObtainedMarks;
    double percentage;

    // Helper to determine grade based on percentage
    char calculateGrade() const {
        if (percentage >= 90) return 'A';
        if (percentage >= 80) return 'B';
        if (percentage >= 70) return 'C';
        if (percentage >= 60) return 'D';
        if (percentage >= 40) return 'E';
        return 'F'; // Fail
    }

public:
    // Constructor
    Student(string n, int roll) {
        name = n;
        rollNumber = roll;
        totalMaxMarks = 0;
        totalObtainedMarks = 0;
        percentage = 0.0;
    }

    // Add a subject to the student's record
    void addSubject(const string& subName, int maxM, int obM) {
        Subject sub = {subName, maxM, obM};
        subjects.push_back(sub);
        totalMaxMarks += maxM;
        totalObtainedMarks += obM;
        if (totalMaxMarks > 0) {
            percentage = (static_cast<double>(totalObtainedMarks) / totalMaxMarks) * 100;
        }
    }

    // Display the formatted marksheet
    void displayMarksheet() const {
        cout << "\n=============================================\n";
        cout << "              STUDENT MARKSHEET              \n";
        cout << "=============================================\n";
        cout << " Name: " << name << setw(25) << "Roll No: " << rollNumber << "\n";
        cout << "---------------------------------------------\n";
        cout << left << setw(20) << "Subject" 
             << right << setw(12) << "Max Marks" 
             << right << setw(12) << "Obtained" << "\n";
        cout << "---------------------------------------------\n";
        
        for (const auto& sub : subjects) {
            cout << left << setw(20) << sub.name 
                 << right << setw(12) << sub.maxMarks 
                 << right << setw(12) << sub.obtainedMarks << "\n";
        }
        
        cout << "---------------------------------------------\n";
        cout << " Total Marks:      " << totalObtainedMarks << " / " << totalMaxMarks << "\n";
        cout << fixed << setprecision(2);
        cout << " Percentage:       " << percentage << "%\n";
        cout << " Final Grade:      " << calculateGrade() << "\n";
        cout << " Status:           " << (calculateGrade() == 'F' ? "FAILED" : "PASSED") << "\n";
        cout << "=============================================\n\n";
    }

    int getRollNumber() const { return rollNumber; }
};

// Main function managing the system flow
int main() {
    vector<Student> database;
    int choice;

    cout << "Welcome to the Marksheet Generation System\n";

    while (true) {
        cout << "1. Add Student & Generate Marksheet\n";
        cout << "2. View All Marksheets\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting system. Goodbye!\n";
            break;
        }

        if (choice == 1) {
            string name;
            int roll, numSubjects;

            cout << "\nEnter Student Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter Number of Subjects: ";
            cin >> numSubjects;

            Student newStudent(name, roll);

            for (int i = 0; i < numSubjects; ++i) {
                string subName;
                int maxM, obM;

                cout << "\n  Enter Subject " << (i + 1) << " Name: ";
                cin.ignore();
                getline(cin, subName);
                cout << "  Enter Max Marks: ";
                cin >> maxM;
                cout << "  Enter Obtained Marks: ";
                cin >> obM;

                newStudent.addSubject(subName, maxM, obM);
            }

            // Immediately display the individual generated marksheet
            newStudent.displayMarksheet();
            
            // Save to database
            database.push_back(newStudent);

        } else if (choice == 2) {
            if (database.empty()) {
                cout << "\nNo records found in the system.\n\n";
            } else {
                for (const auto& student : database) {
                    student.displayMarksheet();
                }
            }
        } else {
            cout << "Invalid selection. Please try again.\n\n";
        }
    }

    return 0;
}
