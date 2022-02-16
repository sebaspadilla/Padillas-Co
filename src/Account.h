#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using std::string;

class Account {
    protected:
        const short id;
        const string name;
        const string surname;
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

        void setAge(short newAge);

        void printAccount();
        void addCredit(int amount);
        virtual int withdrawCredit() = 0;
};

#endif
