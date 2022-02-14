#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using std::string;

class Account {
    private:
        const short id;
        string name;
        string surname;
        short age;
        bool isAdult;

    public:
        Account(short id, string name, string surname, short age);
        short getId();
        string getName();
        string getSurname();
        short getAge();
        bool getIsAdult();

        void printAccount();
};

#endif
