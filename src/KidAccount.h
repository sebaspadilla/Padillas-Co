#ifndef KIDACCOUNT_H
#define KIDACCOUNT_H

#include "Account.h"

class KidAccount : public Account {

    public:
        KidAccount(short id, string name, string surname, short age);
        int withdrawCredit();

};

#endif