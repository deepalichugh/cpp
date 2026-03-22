#include "AccountView.hpp"
#include "Bank.hpp"

namespace AccountController {
    void run() {
        int choice;

        while (true) {
            int choice;
            AccountView::displayMenu();
            choice = AccountView::getUserChoice();

            switch (choice) {
                case 1: {
                    std::string name;
                    int accountNumber;
                    name = AccountView::getAccountHolderName();
                    Account acc(name);
                    accountNumber = acc.getAccountNumber();
                    accounts[accountNumber] = acc;
                    AccountView::displayAccountNumber(accountNumber);
                    break;
                }

                case 2: {
                    int accountNumber;
                    double amount;
                    accountNumber = AccountView::getAccountDetails(accounts, "Enter your account number: ");
                    amount = AccountView::getAmount();
                    Bank::
                    accounts.at(accountNumber).deposit(amount);
                    break;
                }

                case 3: {
                    int accountNo;
                    accountNo = AccountView::getAccountDetails(accounts, "Enter your account number: ");
                    double amount;
                    amount = AccountView::getAmount();
                    accounts.at(accountNo).withdraw(amount);
                    break;
                }

                case 4: {
                    int accountNo;
                    double accBalance;
                    accountNo = AccountView::getAccountDetails(accounts, "Enter your account number: ");
                    accBalance = accounts.at(accountNo).getBalance();
                    AccountView::printAccountBalance(accBalance);
                    break;
                }

                case 5: {
                    int senderAccountNo;
                    int receiverAccountNo;
                    double amount;

                    senderAccountNo = AccountView::getAccountDetails(accounts, "Enter your account number: ");
                    receiverAccountNo = AccountView::getAccountDetails(accounts, "Enter the account number to transfer to: ");

                    amount = AccountView::getAmount();
                    if (accounts.at(senderAccountNo).getBalance() < amount) {
                        AccountView::printError("You do not have sufficient balance to transfer!");
                        break;
                    }
                    accounts.at(senderAccountNo).withdraw(amount);
                    accounts.at(receiverAccountNo).deposit(amount);

                    break;
                }

                case 6:
                    return;

                default:
                    break;
            }
        }
    }
}
