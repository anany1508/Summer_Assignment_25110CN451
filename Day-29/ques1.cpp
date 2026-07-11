#include <iostream>

using namespace std;

int main() {
    int choice;
    double num1, num2, result;

    do {
        // Display the Calculator Menu
        cout << "\n===============================" << endl;
        cout << "     MENU DRIVEN CALCULATOR    " << endl;
        cout << "===============================" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Process user exit option immediately
        if (choice == 5) {
            cout << "\nExiting calculator program. Goodbye!" << endl;
            break;
        }

        // Validate choice range before asking for numbers
        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            // Perform chosen arithmetic logic
            switch (choice) {
                case 1:
                    result = num1 + num2;
                    cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                    break;
                case 2:
                    result = num1 - num2;
                    cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                    break;
                case 3:
                    result = num1 * num2;
                    cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                    break;
                case 4:
                    // Check logic to handle division by zero safely
                    if (num2 != 0) {
                        result = num1 / num2;
                        cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                    } else {
                        cout << "Error: Division by zero is not allowed!" << endl;
                    }
                    break;
            }
        } else {
            cout << "Invalid choice! Please select an option between 1 and 5." << endl;
        }

    } while (choice != 5);

    return 0;
}
