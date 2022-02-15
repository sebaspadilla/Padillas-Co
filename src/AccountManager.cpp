#include "AccountManager.h"
#include "AdultAccount.h"
#include "KidAccount.h"
#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;

int AccountManager::openAccount() {
    short id;
    string name;
    string surname;
    short age;

    cout << "-> OPEN A NEW ACCOUNT" << endl;
    cout << "Enter the holder's first name: ";
    cin >> name;
    cout << "Enter the holder's surname: ";
    cin >> surname;
    cout << "Enter the holder's age: ";
    if (!(cin >> age)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.  Try again: ";
        return 1;
    }

    //TODO:check if entered values are correct (unit test?)
    
    id = AccountManager::accMap.size() + 1;

    if (age > 18) {
        accMap.insert(make_pair(id, new AdultAccount(id, name, surname, age)));
    } else {
        accMap.insert(make_pair(id, new KidAccount(id, name, surname, age)));
    }

    cout << "\nAccount created with ID " << id << endl;

    return 0;
}

int AccountManager::viewAccount() {
    Account* acc;
    short id;

    cout << "-> VIEW ACCOUNT:" << endl;
    acc = selectAccount();
    if (acc == NULL) { return 1; }

    acc->printAccount();
    return 0;
}

int AccountManager::manageAccount() {
    Account* acc;
    int option = 0;

    cout << "-> MANAGE ACCOUNT:" << endl;
    acc = selectAccount();
    if (acc == NULL) { return 1; }

    cout << "Account " << acc->getId() << " selected (" << acc->getName();
    cout << " " << acc->getSurname() << ")" << endl;
    while(option != 4) {
        cout << "\nSelect an option:" << endl;
        cout << "[1] Add credit" << endl;
        cout << "[2] Withdraw credit" << endl;
        cout << "[3] Set age" << endl;
        cout << "[4] Return" << "\n\n" << "Selection: ";
        cin >> option;

        switch(option) {
            case 1:
                acc->addCredit();
                break;

            case 2:
                acc->withdrawCredit();
                break;

            case 3:
                short newAge;
                cout << "New age: ";
                cin >> newAge;
                acc->setAge(newAge);
                break;

            case 4:
                cout << "Returning..." << endl;
                break;

            default:
                cout << "You must select one of the available options" << endl;
        }
    }

    return 0;
}

int AccountManager::deleteAccount() {
    Account* acc;

    cout << "-> DELETE ACCOUNT" << endl;
    acc = selectAccount();
    if (acc == NULL) { return 1; }

    accMap.erase(acc->getId());
    //TODO:change account pointers for smart_pointers
    cout << "Account " << acc->getId() << " deleted (" << acc->getName();
    cout << " " << acc->getSurname() << ")" << endl;
}

Account* AccountManager::selectAccount() {
    short id;

    cout << "Enter the account's ID: ";
    cin >> id;
    //TODO: todas partes donde se introduzca un int hacer check?
    if (accMap.find(id) == accMap.end()) {
        cout << "No account exists with the given ID" << endl;
        return NULL;
    }

    return accMap[id];
}