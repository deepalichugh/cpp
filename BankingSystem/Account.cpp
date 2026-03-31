#include "Account.hpp"

int Account::accountNumberCounter = 1;

Account::Account(std::string& holderName)
  : accountNumber(accountNumberCounter++), accountHolderName(holderName), balance(0.0) {};

int Account::getAccountNumber() {
  return accountNumber;
}

bool Account::deposit(double& amount) {
  if (amount < 0) {
    return false;
  }

  balance += amount;
  return true;
}

bool Account::withdraw(double& amount) {
  if (amount <= 0 || amount > balance) {
    return false;
  }

  balance -= amount;
  return true;
}

double Account::getBalance() {
  return balance; 
}