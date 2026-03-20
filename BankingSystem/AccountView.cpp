#include "AccountView.hpp"

namespace AccountView {
    int getAccountDetails(std::unordered_map<int, Account>& accounts) {
        int accountNumber;
        std::cin >> accountNumber;
        
        while (accounts.find(accountNumber) == accounts.end()) {
            std::cout << "This account number doesn't exist. Try again!\nEnter account number:";
            std::cin >> accountNumber;
        }

        return accountNumber;
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

    int getUserChoice() {
        int choice;
        std::cin >> choice;

        return choice;
    }
}