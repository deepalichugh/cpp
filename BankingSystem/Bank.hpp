#pragma once
#include "Account.hpp"
#include <unordered_map>
#include <stdexcept>

class Bank {
    static std::unordered_map<int, Account> accounts;

    public:
        Account getAccount(int accountNumber) {}
}