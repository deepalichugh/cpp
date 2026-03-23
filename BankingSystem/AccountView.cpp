#include "AccountView.hpp"

namespace AccountView {
    int getAccountNumberMessage(std::string& message, bool hasError) {
        int accountNumber;
        if (hasError) {
            std::cout << "This account number doesn't exist. Try again!\nEnter account number: ";
        } else {
            std::cout << message;
        }
        std::cin >> accountNumber;

        return accountNumber;
    }

    void printError(const std::string& message) {
        std::cout << message << std::endl;
    }

    double getAmount() {
        double amount;
        std::cout << "Enter the amount: ";
        std::cin >> amount;

        while (amount <= 0) {
            std::cout << "The amount value cannot be negative or zero! Enter the amount: ";
            std::cin >>amount;
        }

        return amount;
    }

    std::string getAccountHolderName() {
        std::string name;
        std::cout << "Enter account holder name: ";
        std::cin >> name;

        return name;
    }

    void printAccountBalance(double balance) {
        std::cout << "Your account balance is: " << balance << std::endl;
    }

    int getUserChoice() {
        int choice;
        std::cin >> choice;

        return choice;
    }

    void displayMenu() {
        std::cout << "\nMenu options:\n";
        std::cout << "1. Create Account \n";
        std::cout << "2. Deposit \n";
        std::cout << "3. Withdraw \n";
        std::cout << "4. Check Balance \n";
        std::cout << "5. Transfer Funds \n";
        std::cout << "6. Exit \n";
        std::cout << "Enter your choice \n";
    }

    void displayAccountNumber(int accountNumber) {
        std::cout << "Your Account number is: " << accountNumber << std::endl;
    }
}