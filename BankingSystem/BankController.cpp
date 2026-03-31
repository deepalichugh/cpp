#include "AccountView.hpp"
#include "BankController.hpp"
#include "Bank.hpp"

void BankController::tryCreateAccount() {
    std::string name;
    int accountNumber;
    AccountView::prompt("Enter account holder name: ");
    name = AccountView::getInput<std::string>();
    accountNumber = BankController::bank.createAccount(name);
    AccountView::prompt("Your account number is: ", accountNumber);
}

Account* BankController::tryGetAccount(std::string message) {
    int accountNumber;
    AccountView::prompt(message);
    accountNumber = AccountView::getInput<int>();

    auto* account = BankController::bank.getAccount(accountNumber);

    while (account == nullptr) {
        AccountView::prompt("This account number doesn't exist. Try again!\nEnter account number: ");
        accountNumber = AccountView::getInput<int>();
        account = BankController::bank.getAccount(accountNumber);
    }

    return account;
}

void BankController::tryDeposit() {
    auto* acc = tryGetAccount("Enter your account number: ");
    AccountView::prompt("Enter the amount to deposit: ");
    double amount = AccountView::getInput<double>();
    bool isSuccessfulDeposit = acc->deposit(amount);

    while (!isSuccessfulDeposit) {
        AccountView::prompt("Enter the amount to deposit: ");
        amount = AccountView::getInput<double>();
        isSuccessfulDeposit = acc->deposit(amount);
    }
}

void BankController::tryWithdraw() {
    auto* acc = tryGetAccount("Enter your account number: ");
    AccountView::prompt("Enter the amount to withdraw: ");
    double amount = AccountView::getInput<double>();
    bool isSuccessfulWithdraw = acc->withdraw(amount);

    while (!isSuccessfulWithdraw) {
        AccountView::prompt("Enter the amount to withdraw: ");
        amount = AccountView::getInput<double>();
        isSuccessfulWithdraw = acc->withdraw(amount);
    }
}

void BankController::tryTransferFunds() {
    auto* acc1 = tryGetAccount("Enter your account number: ");
    auto* acc2 = tryGetAccount("Enter receiver's account number: ");
    AccountView::prompt("Enter the amount to transfer: ");
    double amount = AccountView::getInput<double>();
    bool isSuccessfulWithdraw = acc1->withdraw(amount);

    while (!isSuccessfulWithdraw) {
        AccountView::prompt("Enter the amount to transfer: ");
        amount = AccountView::getInput<double>();
        isSuccessfulWithdraw = acc1->withdraw(amount);
    }

    acc2->deposit(amount);
}

void BankController::tryGetBalance() {
    auto* acc = tryGetAccount("Enter your account number: ");
    AccountView::prompt("Your account balance is: ", acc->getBalance());
}