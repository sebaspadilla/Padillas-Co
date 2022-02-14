#include "AccountManager.h"
#include <iostream>

using namespace std;

int main() {
    AccountManager* accManager = new AccountManager();
    int option = 0;

    cout << "\nWelcome to Padillas-Co" << endl;
    while (option != 5) {
        cout << "Select an option: " << endl;
        cout << "[1] Create a new account" << endl;
        cout << "[2] View an existing account" << endl;
        cout << "[5] Quit" << endl;
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:
                accManager->openAccount();
                break;

            case 2:
                accManager->viewAccount();
                break;

            case 5:
                cout << "Goodbye :)" << endl;
                break;

            default:
                cout << "You must select one of the available options" << endl;
        }

        cout << endl;
    }

    return 0;
}