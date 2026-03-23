#include "AccountView.hpp"
#include "Bank.hpp"
#include "Account.hpp"

namespace AccountController {
    Account& checkAccountExists(std::string message, Bank& bank) {
        int accountNumber;
        accountNumber = AccountView::getAccountNumberMessage(message, false);

        while (true) {
            try {
                return bank.getAccount(accountNumber);
            } catch (const std::exception& e) {
                accountNumber = AccountView::getAccountNumberMessage(message, true);
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
                    int accountNumber;
                    double amount;
                    Account& acc = checkAccountExists("Enter your account number: ", bankObj);
                    amount = AccountView::getAmount();
                    acc.deposit(amount);
                    break;
                }

                case 3: {
                    int accountNo;
                    Account& acc = checkAccountExists("Enter your account number: ", bankObj);
                    double amount;
                    amount = AccountView::getAmount();
                    acc.withdraw(amount);
                    break;
                }

                case 4: {
                    double balance;
                    Account& acc = checkAccountExists("Enter your account number: ", bankObj);
                    balance = acc.getBalance();
                    AccountView::printAccountBalance(balance);
                    break;
                }

                case 5: {
                    int senderAccountNo;
                    int receiverAccountNo;
                    double amount;

                    Account& senderAccount = checkAccountExists("Enter your account number: ", bankObj);
                    Account& receiverAccount = checkAccountExists("Enter the account number to transfer to: ", bankObj);

                    amount = AccountView::getAmount();
                    senderAccount.withdraw(amount);
                    receiverAccount.deposit(amount);

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
