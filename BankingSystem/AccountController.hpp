#pragma once
#include "Bank.hpp"
#include "Account.hpp"
#include <unordered_map>

namespace AccountController {
    Account& getExistingAccount(std::string message, Bank& bank);
    void run();
}