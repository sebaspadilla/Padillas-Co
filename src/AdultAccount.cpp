#include "AdultAccount.h"

AdultAccount::AdultAccount(short id, string name, string surname, short age) : 
    Account(id, name, surname, age, true) {}

void AdultAccount::withdrawCredit(int amount) {
    credit -= amount;
}