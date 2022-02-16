#include "Account.h"
#include "Tools.h"
#include <iostream>
#include <string>

using namespace std;

Account::Account(short id, string name, string surname, short age, bool isAdult) :
    id(id), name(name), surname(surname), age(age), isAdult(isAdult), credit(0) {}

// Getters
short Account::getId() { return id; }
string Account::getName() { return name; }
string Account::getSurname() { return surname; }
short Account::getAge() { return age; }
bool Account::getIsAdult() { return isAdult; }

void Account::setAge(short newAge) {
    age = newAge;
}

//TODO: complete CRUD

void Account::printAccount() {
    cout << "ACCOUNT INFO:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Age: " << age;
    cout << "\tThe account's holder is " << (isAdult ? "" : "not ") << "an adult." << endl;
    cout << "Credit: " << credit << endl;
}

void Account::addCredit(int amount) {
    credit += amount;
    cout << amount << " units added to credit" << endl;
}

