#pragma once
#include "Account.hpp"
#include <unordered_map>
#include <stdexcept>
#include <optional>

class Bank {
    static std::unordered_map<int, Account> bank;
    
    public:
        static int accountNumberCounter;
        int createAccount(std::string name);
        Account* getAccount(int accountNumber);
};