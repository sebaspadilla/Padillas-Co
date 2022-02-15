#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using std::string;

class Account {
    protected:
        const short id;
        string name;
        string surname;
        short age;
        const bool isAdult;
        int credit;

    public:
        Account(short id, string name, string surname, short age, bool isAdult);
        short getId();
        string getName();
        string getSurname();
        short getAge();
        bool getIsAdult();

        void printAccount();
        void addCredit(int amount);
        virtual void withdrawCredit(int amount) = 0;
};

#endif
