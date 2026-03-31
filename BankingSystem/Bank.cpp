#include "Bank.hpp"

std::unordered_map<int, Account> Bank::bank;

int Bank::createAccount(std::string name) {
    Account acc(name);
    int accountNumber = acc.getAccountNumber();
    Bank::bank.emplace(accountNumber, std::move(acc));

    return accountNumber;
}

Account* Bank::getAccount(int accountNumber) {
    auto bankAccount = Bank::bank.find(accountNumber);
    if (bankAccount == Bank::bank.end()) {
        return nullptr;
    }

    return &(bankAccount->second);
}
