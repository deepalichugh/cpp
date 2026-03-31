#include "AccountView.hpp"

namespace AccountView {
    void prompt(std::string msg) {
        std::cout << msg;
    }


    void displayMenu() {
        std::cout << "\nMenu options:\n";
        std::cout << "1. Create Account \n";
        std::cout << "2. Deposit \n";
        std::cout << "3. Withdraw \n";
        std::cout << "4. Check Balance \n";
        std::cout << "5. Transfer Funds \n";
        std::cout << "6. Exit \n";
        std::cout << "Enter your choice \n";
    }
}