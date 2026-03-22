#include "Account.hpp"
#include <unordered_map>
#include <stdexcept>

class Bank {
    static std::unordered_map<int, Account> accounts;

    public:
        Account getAccount(int accountNumber) {
            int account = accounts.at(accountNumber).getAccountNumber();
            if (accounts.find(account) == accounts.end()) {
                throw std::runtime_error("This account doesn't exist!");
            }

            return accounts.at(accountNumber);
        }
};