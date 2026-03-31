#pragma once
#include <iostream>
#include <string>

class Account {
  private:
    int accountNumber;
    std::string accountHolderName;
    double balance;
    static int accountNumberCounter;

  public:
    Account(std::string& holderName);

    int getAccountNumber();

    bool deposit(double& amount);

    bool withdraw(double& amount);

    double getBalance();
};
