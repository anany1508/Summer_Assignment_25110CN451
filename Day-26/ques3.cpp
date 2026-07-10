#include <iostream>
#include <string>

class ATM {
private:
    std::string accountHolder;
    int accountNumber;
    int pinCode;
    double balance;

public:
    // Constructor to initialize account data
    ATM(std::string name, int accNum, int pin, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        pinCode = pin;
        balance = initialBalance;
    }

    // Getter for security verification
    int getPin() const { return pinCode; }
    std::string getName() const { return accountHolder; }

    // Core ATM Features
    void checkBalance() const {
        std::cout << "\n--- Account Balance ---" << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "\nSuccessfully deposited $" << amount << std::endl;
            std::cout << "New Balance: $" << balance << std::endl;
        } else {
            std::cout << "\nInvalid deposit amount!" << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "\nInvalid withdrawal amount!" << std::endl;
        } else if (amount > balance) {
            std::cout << "\nTransaction Declined: Insufficient funds!" << std::endl;
        } else {
            balance -= amount;
            std::cout << "\nSuccessfully withdrew $" << amount << std::endl;
            std::cout << "Remaining Balance: $" << balance << std::endl;
        }
    }
};

int main() {
    // Create a mock user account (Name, Account Number, PIN, Initial Balance)
    ATM userAccount("Jane Doe", 987654, 4321, 1500.50);

    int enteredPin;
    int loginAttempts = 0;
    bool authenticated = false;

    std::cout << "=====================================" << std::endl;
    std::cout << "    WELCOME TO THE ATM SIMULATOR     " << std::endl;
    std::cout << "=====================================" << std::endl;

    // PIN Authentication loop (Maximum 3 attempts)
    while (loginAttempts < 3) {
        std::cout << "Enter your 4-digit PIN: ";
        std::cin >> enteredPin;

        if (enteredPin == userAccount.getPin()) {
            authenticated = true;
            break;
        } else {
            loginAttempts++;
            std::cout << "Incorrect PIN. Attempts remaining: " << (3 - loginAttempts) << "\n" << std::endl;
        }
    }

    if (!authenticated) {
        std::cout << "Card blocked due to too many failed login attempts." << std::endl;
        return 0; // Terminate program
    }

    // Authenticated session menu loop
    int choice;
    do {
        std::cout << "\n===============================" << std::endl;
        std::cout << "Hello, " << userAccount.getName() << "! Select an option:" << std::endl;
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Deposit Cash" << std::endl;
        std::cout << "3. Withdraw Cash" << std::endl;
        std::cout << "4. Exit Session" << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << "Enter Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                userAccount.checkBalance();
                break;
            case 2: {
                double depAmount;
                std::cout << "Enter deposit amount: $";
                std::cin >> depAmount;
                userAccount.deposit(depAmount);
                break;
            }
            case 3: {
                double drawAmount;
                std::cout << "Enter withdrawal amount: $";
                std::cin >> drawAmount;
                userAccount.withdraw(drawAmount);
                break;
            }
            case 4:
                std::cout << "\nThank you for choosing our bank. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "\nInvalid selection. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
