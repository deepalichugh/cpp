#include "Bank.hpp"
#include <stdexcept>

std::unordered_map<int, Account> Bank::accounts;

int Bank::createAccount(std::string name) {
    Account acc(name);
    int accountNumber;
    accountNumber = acc.getAccountNumber();
    Bank::accounts[accountNumber] = acc;

    return accountNumber;
}

Account& Bank::getAccount(int accountNumber) {
    int account = Bank::accounts.at(accountNumber).getAccountNumber();
    if (Bank::accounts.find(account) == Bank::accounts.end()) {
        throw std::runtime_error("This account doesn't exist!");
    }

    return Bank::accounts.at(accountNumber);
}