#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    std::string accountType; // "Savings" or "Current"
    double balance;

public:
    // Constructor to initialize an account
    BankAccount(int accNum, std::string name, std::string type, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = name;
        accountType = type;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    // Getter for account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "\n[Success] Deposit of $" << std::fixed << std::setprecision(2) 
                      << amount << " was successful!\n";
        } else {
            std::cout << "\n[Error] Invalid deposit amount.\n";
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "\n[Error] Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            std::cout << "\n[Error] Insufficient funds! Available balance: $" 
                      << std::fixed << std::setprecision(2) << balance << "\n";
        } else {
            balance -= amount;
            std::cout << "\n[Success] Withdrawal of $" << std::fixed << std::setprecision(2) 
                      << amount << " was successful!\n";
        }
    }

    // Function to display specific account details
    void displayAccountInfo() const {
        std::cout << "\n-----------------------------------";
        std::cout << "\n       Account Summary             ";
        std::cout << "\n-----------------------------------";
        std::cout << "\nAccount Number : " << accountNumber;
        std::cout << "\nHolder Name    : " << accountHolderName;
        std::cout << "\nAccount Type   : " << accountType;
        std::cout << "\nCurrent Balance: $" << std::fixed << std::setprecision(2) << balance;
        std::cout << "\n-----------------------------------\n";
    }
};

// Helper function to find an account index by its account number
int findAccount(const std::vector<BankAccount>& accounts, int accNum) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getAccountNumber() == accNum) {
            return i; // Returns index of the found account
        }
    }
    return -1; // Returns -1 if account does not exist
}

int main() {
    std::vector<BankAccount> bankAccounts;
    int choice;
    int nextAccNum = 1001; // Starts automatic generation of unique account numbers

    std::cout << "=== Welcome to the Bank Management System ===\n";

    do {
        std::cout << "\nMAIN MENU\n";
        std::cout << "1. Open New Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Check Account Details\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        // Clear input buffer to handle potential string inputs seamlessly
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string name, type;
                double initialDeposit;
                int typeChoice;

                std::cout << "\nEnter Account Holder Full Name: ";
                std::getline(std::cin, name);

                std::cout << "Select Account Type:\n1. Savings\n2. Current\nChoice: ";
                std::cin >> typeChoice;
                type = (typeChoice == 2) ? "Current" : "Savings";

                std::cout << "Enter Initial Deposit Amount: $";
                std::cin >> initialDeposit;

                // Create a new BankAccount object and add it to the collection
                BankAccount newAccount(nextAccNum, name, type, initialDeposit);
                bankAccounts.push_back(newAccount);

                std::cout << "\n[Success] Account created successfully!";
                std::cout << "\nYour assigned Account Number is: " << nextAccNum << "\n";
                nextAccNum++; // Increment for the next user
                break;
            }
            case 2: {
                int accNum;
                double amount;
                std::cout << "\nEnter your Account Number: ";
                std::cin >> accNum;

                int index = findAccount(bankAccounts, accNum);
                if (index != -1) {
                    std::cout << "Enter deposit amount: $";
                    std::cin >> amount;
                    bankAccounts[index].deposit(amount);
                } else {
                    std::cout << "\n[Error] Account number not found.\n";
                }
                break;
            }
            case 3: {
                int accNum;
                double amount;
                std::cout << "\nEnter your Account Number: ";
                std::cin >> accNum;

                int index = findAccount(bankAccounts, accNum);
                if (index != -1) {
                    std::cout << "Enter withdrawal amount: $";
                    std::cin >> amount;
                    bankAccounts[index].withdraw(amount);
                } else {
                    std::cout << "\n[Error] Account number not found.\n";
                }
                break;
            }
            case 4: {
                int accNum;
                std::cout << "\nEnter your Account Number: ";
                std::cin >> accNum;

                int index = findAccount(bankAccounts, accNum);
                if (index != -1) {
                    bankAccounts[index].displayAccountInfo();
                } else {
                    std::cout << "\n[Error] Account number not found.\n";
                }
                break;
            }
            case 5:
                std::cout << "\nThank you for choosing our banking services. Goodbye!\n";
                break;
            default:
                std::cout << "\n[Error] Invalid choice! Please select an option between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
