#include "AccountView.hpp"
#include "Bank.hpp"

namespace AccountController {
    Account& getExistingAccount(std::string message, Bank& bank) {
        int accountNumber;
        accountNumber = AccountView::promptAccountNumber(message, false);

        while (true) {
            try {
                return bank.getAccount(accountNumber);
            } catch (const std::exception& e) {
                accountNumber = AccountView::promptAccountNumber(message, true);
            }
        }
    }

    void run() {
        Bank bankObj;
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
                    accountNumber = bankObj.createAccount(name);
                    AccountView::displayAccountNumber(accountNumber);
                    break;
                }

                case 2: {
                    double amount;
                    Account& acc = getExistingAccount("Enter your account number: ", bankObj);
                    amount = AccountView::getAmount();
                    acc.deposit(amount);
                    break;
                }

                case 3: {
                    Account& acc = getExistingAccount("Enter your account number: ", bankObj);
                    double amount;
                    amount = AccountView::getAmount();
                    acc.withdraw(amount);
                    break;
                }

                case 4: {
                    double balance;
                    Account& acc = getExistingAccount("Enter your account number: ", bankObj);
                    balance = acc.getBalance();
                    AccountView::printAccountBalance(balance);
                    break;
                }

                case 5: {
                    Account& senderAccount = getExistingAccount("Enter your account number: ", bankObj);
                    Account& receiverAccount = getExistingAccount("Enter the account number to transfer to: ", bankObj);

                    double amount;
                    amount = AccountView::getAmount();
                    senderAccount.withdraw(amount);
                    receiverAccount.deposit(amount);

                    break;
                }

                case 6:
                    return;

                default:
                    AccountView::printError("Invalid input! Please select an option from the menu.");
                    break;
            }
        }
    }
}
