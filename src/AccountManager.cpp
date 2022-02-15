#include "AccountManager.h"
#include "AdultAccount.h"
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

    accMap.insert(make_pair(id, new AdultAccount(id, name, surname, age)));

    cout << "\nAccount created with ID " << id << endl;

    return 0;
}

int AccountManager::viewAccount() {

    short id;

    cout << "-> VIEW ACCOUNT:" << endl;
    cout << "Enter the account's ID: ";
    cin >> id;
    
    if (accMap.find(id) == accMap.end()) {
        cout << "No account exists with the given ID" << endl;
        return 1;
    }

    accMap[id]->printAccount();

    return 0;
}
