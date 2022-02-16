#include "KidAccount.h"
#include <iostream>

KidAccount::KidAccount(short id, string name, string surname, short age) : 
    Account(id, name, surname, age, false) {}

int KidAccount::withdrawCredit() {
    std::cout << "Kids cannot withdraw credit" << std::endl;

    return 0;
}