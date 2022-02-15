#include "AdultAccount.h"
#include <iostream>

AdultAccount::AdultAccount(short id, string name, string surname, short age) : 
    Account(id, name, surname, age, true) {}

int AdultAccount::withdrawCredit() {
    int amount;

    std::cout << "Enter amount of credit to withdraw: ";
    std::cin >> amount;
    if (amount > credit) {
        std::cout << "Not enough credit" << std::endl;
        
        return 1;
    }

    credit -= amount;
    std::cout << "\n" << amount << " units withdrawed from credit" << std::endl;

    return 0;
}