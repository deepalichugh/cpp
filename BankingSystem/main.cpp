#include "BankController.hpp"
#include "AccountView.hpp"

int main() {
    BankController controller;
    int choice;

    while (true) {
        AccountView::displayMenu();
        choice = AccountView::getInput<int>();

        switch (choice) {
            case 1: {
                controller.tryCreateAccount();
                break;
            }

            case 2: {
                controller.tryDeposit();
                break;
            }

            case 3: {
                controller.tryWithdraw();
                break;
            }

            case 4: {
                controller.tryGetBalance();
                break;
            }

            case 5: {
                controller.tryTransferFunds();
                break;
            }

            case 6:
                return 0;

            default:
                AccountView::prompt("Invalid input! Please select an option from the menu.");
                break;
        }
    }

    return 0;
}
