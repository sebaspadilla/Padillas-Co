#include "AccountManager.h"
#include "Tools.h"
#include <iostream>

using namespace std;

int main() {
    AccountManager* accManager = new AccountManager();
    int option = 0;

    cout << "\n--------------------------------" << endl;
    cout << "---  Welcome to Padillas-Co  ---" << endl;
    cout << "--------------------------------\n\n";
    while (option != 7) {
        cout << "Select an option: " << endl;
        cout << "[1] Create a new account" << endl;
        cout << "[2] View an existing account" << endl;
        cout << "[3] Manage an account" << endl;
        cout << "[4] Delete an account" << endl;
        cout << "[5] View open accounts" << endl;
        cout << "[7] Quit" << "\n\n" << "Selection: ";
        tools::safeCin<int>(option);
        cout << endl;

        switch (option) {
            case 1:
                accManager->openAccount();
                break;

            case 2:
                accManager->viewAccount();
                break;

            case 3:
                accManager->manageAccount();
                break;

            case 4:
                accManager->deleteAccount();
                break;

            case 5:
                accManager->printAccountsList();
                break;

            case 7:
                cout << "Goodbye :)" << endl;
                break;

            default:
                cout << "You must select one of the available options" << endl;
        }

        cout << endl;
    }

    return 0;
}