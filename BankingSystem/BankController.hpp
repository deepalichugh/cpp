#pragma once
#include "Bank.hpp"
#include "Account.hpp"
#include <string>

class BankController {
    private:
        Bank bank;
    public:
        Account* tryGetAccount(std::string message);
        void tryCreateAccount();
        void tryDeposit();
        void tryWithdraw();
        void tryGetBalance();
        void tryTransferFunds();
};
