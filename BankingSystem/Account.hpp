#pragma once
#include <iostream>

class Account {
  int accountNumber;
  std::string accountHolderName;
  double balance;
  static int accountNumberCounter;

  public:
    Account();
    Account(std::string holderName);

    int getAccountNumber();

    void deposit(double& amount);

    void withdraw(double& amount);

    double getBalance();
};
