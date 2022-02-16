#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "Account.h"
#include <map>
#include <memory>

class AccountManager {

    private:
        std::map<short, std::shared_ptr<Account>> accMap;
        std::shared_ptr<Account> selectAccount();
    
    public:
        int openAccount();
        int viewAccount();
        int manageAccount();
        int deleteAccount();
        void printAccountsList();

};

#endif