#pragma once
#include "Account.hpp"
#include <unordered_map>

namespace AccountView {
    int getAccountDetails(std::unordered_map<int, Account>& accounts);
    double getAmount();
    void displayMenu();
    int getUserChoice();
}