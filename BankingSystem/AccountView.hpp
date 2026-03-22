#pragma once
#include "Account.hpp"
#include <unordered_map>
#include <string>

namespace AccountView {
    int getAccountDetails(std::unordered_map<int, Account>& accounts, const std::string& message);
    void printAccountDetails(int accountNumber);
    double getAmount();
    void displayAccountNumber(int accountNumber);
    void printAccountBalance(double balance);
    void printError(const std::string& message);
    void displayMenu();
    int getUserChoice();
    std::string getAccountHolderName();
}