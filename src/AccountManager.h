#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "Account.h"
#include <map>

class AccountManager {

    private:
        std::map<short, Account*> accMap;
        Account* selectAccount();
    
    public:
        int openAccount();
        int viewAccount();
        int manageAccount();
        int deleteAccount();

};

#endif