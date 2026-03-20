#include "Account.hpp"
#include <iostream>
#include <unordered_map>
#include <stdexcept>

int Account::accountNumberCounter = 1;

Account::Account() {}

Account::Account(std::string holderName) {
  Account::accountNumber = accountNumberCounter++;
  Account::accountHolderName = holderName;
  Account::balance = 0.0;
};

int Account::getAccountNumber() {
  return accountNumber;
}

void Account::deposit(double& amount) {
  balance += amount;
}

void Account::withdraw(double& amount) {
  if (amount > balance) {
    throw std::runtime_error("You have insufficient balance!");
  }

  balance -= amount;
}

double Account::getBalance() {
  return balance; 
}
