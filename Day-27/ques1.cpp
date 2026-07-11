#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Class representing an individual Student
class Student {
private:
    int rollNumber;
    string name;
    int age;
    string course;

public:
    // Constructor to initialize student details
    Student(int r, string n, int a, string c) {
        rollNumber = r;
        name = n;
        age = a;
        course = c;
    }

    // Getters
    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCourse() const { return course; }

    // Setters for updating records
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setCourse(string c) { course = c; }

    // Display student details in a formatted row
    void displayRow() const {
        cout << left << setw(15) << rollNumber 
             << setw(25) << name 
             << setw(10) << age 
             << setw(20) << course << endl;
    }
};

// Class managing the system operations
class StudentManagementSystem {
private:
    vector<Student> students;

    // Helper method to find student index by roll number
    int findStudentIndex(int roll) {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].getRollNumber() == roll) {
                return i; // Found
            }
        }
        return -1; // Not Found
    }

public:
    // 1. Add a new student record
    void addStudent() {
        int roll, age;
        string name, course;

        cout << "\nEnter Roll Number: ";
        cin >> roll;
        
        // Prevent duplicate roll numbers
        if (findStudentIndex(roll) != -1) {
            cout << "Error: Student with Roll Number " << roll << " already exists!\n";
            return;
        }

        cin.ignore(); // Clear input buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);

        students.push_back(Student(roll, name, age, course));
        cout << "Record added successfully!\n";
    }

    // 2. Display all records
    void displayAll() {
        if (students.empty()) {
            cout << "\nNo records found in the system.\n";
            return;
        }

        cout << "\n------------------------------------------------------------------\n";
        cout << left << setw(15) << "Roll No" << setw(25) << "Name" << setw(10) << "Age" << setw(20) << "Course" << endl;
        cout << "------------------------------------------------------------------\n";
        for (const auto& student : students) {
            student.displayRow();
        }
        cout << "------------------------------------------------------------------\n";
    }

    // 3. Search a student by roll number
    void searchStudent() {
        int roll;
        cout << "\nEnter Roll Number to search: ";
        cin >> roll;

        int index = findStudentIndex(roll);
        if (index != -1) {
            cout << "\nRecord Found:\n";
            cout << "------------------------------------------------------------------\n";
            cout << left << setw(15) << "Roll No" << setw(25) << "Name" << setw(10) << "Age" << setw(20) << "Course" << endl;
            cout << "------------------------------------------------------------------\n";
            students[index].displayRow();
            cout << "------------------------------------------------------------------\n";
        } else {
            cout << "Record not found!\n";
        }
    }

    // 4. Update an existing student record
    void updateStudent() {
        int roll;
        cout << "\nEnter Roll Number to update: ";
        cin >> roll;

        int index = findStudentIndex(roll);
        if (index != -1) {
            string newName, newCourse;
            int newAge;

            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, newName);
            cout << "Enter New Age: ";
            cin >> newAge;
            cin.ignore();
            cout << "Enter New Course: ";
            getline(cin, newCourse);

            students[index].setName(newName);
            students[index].setAge(newAge);
            students[index].setCourse(newCourse);

            cout << "Record updated successfully!\n";
        } else {
            cout << "Record not found!\n";
        }
    }

    // 5. Delete a student record
    void deleteStudent() {
        int roll;
        cout << "\nEnter Roll Number to delete: ";
        cin >> roll;

        int index = findStudentIndex(roll);
        if (index != -1) {
            students.erase(students.begin() + index);
            cout << "Record deleted successfully!\n";
        } else {
            cout << "Record not found!\n";
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Search Student Record\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: sms.addStudent(); break;
            case 2: sms.displayAll(); break;
            case 3: sms.searchStudent(); break;
            case 4: sms.updateStudent(); break;
            case 5: sms.deleteStudent(); break;
            case 6: cout << "\nExiting system. Goodbye!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
