#include "AccountManager.h"
#include "AdultAccount.h"
#include "KidAccount.h"
#include "Tools.h"
#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <memory>

using namespace std;

int AccountManager::openAccount() {
    short id;
    string name;
    string surname;
    short age;

    cout << "-> OPEN A NEW ACCOUNT" << endl;
    cout << "Enter the holder's first name: ";
    tools::safeCin<string>(name);
    cout << "Enter the holder's surname: ";
    tools::safeCin<string>(surname);
    cout << "Enter the holder's age: ";
    tools::safeCin<short>(age);

    //TODO:check if entered values are correct (unit test?)
    
    id = AccountManager::accMap.size() + 1;

    if (age > 18) {
        accMap.insert(make_pair(id, make_shared<AdultAccount>(id, name, surname, age)));
    } else {
        accMap.insert(make_pair(id, make_shared<KidAccount>(id, name, surname, age)));
    }

    cout << "\nAccount created with ID " << id << endl;

    return 0;
}

int AccountManager::viewAccount() {
    shared_ptr<Account> acc;
    short id;

    cout << "-> VIEW ACCOUNT:" << endl;
    acc = selectAccount();
    if (acc == NULL) { return 1; }

    acc->printAccount();
    return 0;
}

int AccountManager::manageAccount() {
    shared_ptr<Account> acc;
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
        tools::safeCin<int>(option);

        switch(option) {
            case 1:
                int amount;
                cout << "Enter amount of credit to add: ";
                tools::safeCin<int>(amount);
                acc->addCredit(amount);
                break;

            case 2:
                acc->withdrawCredit();
                break;

            case 3:
                short newAge;
                cout << "New age: ";
                tools::safeCin<short>(newAge);
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
    shared_ptr<Account> acc;

    cout << "-> DELETE ACCOUNT" << endl;
    acc = selectAccount();
    if (acc == NULL) { return 1; }

    accMap.erase(acc->getId());
    //TODO:change account pointers for smart_pointers
    cout << "Account " << acc->getId() << " deleted (" << acc->getName();
    cout << " " << acc->getSurname() << ")" << endl;
}

shared_ptr<Account> AccountManager::selectAccount() {
    short id;

    cout << "Enter the account's ID: ";
    tools::safeCin<short>(id);
    //TODO: todas partes donde se introduzca un int hacer check?
    if (accMap.find(id) == accMap.end()) {
        cout << "No account exists with the given ID" << endl;
        return NULL;
    }

    return accMap[id];
}

void AccountManager::printAccountsList() {
    cout << "-> OPEN ACCOUNTS:" << endl;
    if (accMap.size() > 0) {
        cout << "ID\tHolder\n";
        for (auto itr = accMap.begin(); itr != accMap.end(); ++itr) {
            cout << itr->first << '\t' << itr->second->getName() << " "
                << itr->second->getSurname() << endl;
        }
    } else {
        cout << "There are no open accounts." << endl;
    }
}
