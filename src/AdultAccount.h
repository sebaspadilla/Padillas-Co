#ifndef ADULTACCOUNT_H
#define ADULTACCOUNT_H

#include "Account.h"

class AdultAccount : public Account {

    public:
        AdultAccount(short id, string name, string surname, short age);
        int withdrawCredit();

};

#endif