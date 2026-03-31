#pragma once
#include "Account.hpp"
#include <unordered_map>
#include <string>
#include <optional>

namespace AccountView {
    void prompt(std::string msg);
    void prompt(std::string msg, auto val) {
        std::cout << msg << val;
    }

    template <typename T>
    T getInput() {
        T val;
        std::cin >> val;
        return val;
    }

    void displayMenu();
}