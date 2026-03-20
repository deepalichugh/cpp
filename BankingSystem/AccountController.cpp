#include "AccountView.hpp"

namespace AccountController {
    void run() {
        std::unordered_map<int, Account> accounts;
        int choice;

        while (true) {
            int choice;
            AccountView::displayMenu();
            choice = AccountView::getUserChoice();

            switch (choice) {
                case 1: {
                    std::string name;
                    std::cout << "Enter account holder name: ";
                    std::cin >> name;
                    Account acc(name);
                    accounts[acc.getAccountNumber()] = acc;
                    std::cout << "Your Account number is: " << acc.getAccountNumber() << std::endl;
                    break;
                }

                case 2: {
                    int accountNumber;
                    double amount;
                    std::cout << "Enter your account number: ";
                    accountNumber = AccountView::getAccountDetails(accounts);
                    amount = AccountView::getAmount();
                    accounts.at(accountNumber).deposit(amount);
                    break;
                }

                case 3: {
                    int accountNo;
                    std::cout << "Enter your account number: ";
                    accountNo = AccountView::getAccountDetails(accounts);
                    double amount;
                    amount = AccountView::getAmount();
                    accounts.at(accountNo).withdraw(amount);
                    break;
                }

                case 4: {
                    int accountNo;
                    double accBalance;
                    std::cout << "Enter your account number: ";
                    accountNo = AccountView::getAccountDetails(accounts);
                    accBalance = accounts.at(accountNo).getBalance();
                    std::cout << "Your account balance is: " << accBalance << std::endl;
                    break;
                }

                case 5: {
                    int senderAccountNo;
                    int receiverAccountNo;
                    double amount;

                    std::cout << "Enter your account number: ";
                    senderAccountNo = AccountView::getAccountDetails(accounts);

                    std::cout << "Enter the account number to transfer to: ";
                    receiverAccountNo = AccountView::getAccountDetails(accounts);

                    amount = AccountView::getAmount();
                    if (accounts.at(senderAccountNo).getBalance() < amount) {
                        std::cout << "You do not have sufficient balance to transfer!";
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
