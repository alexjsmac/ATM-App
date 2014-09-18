#include <iostream>
#include <string>
#include "account.h"

Account::Account(){
	balance = 0;
	type = 0;
}

double Account::getBalance(){
       return balance;
}

bool Account::getType(){
       return type;
}

Account::~Account(){

}

class ChequingAccount: public Account{
public:
	ChequingAccount(){
		balance = 0;
		type = 0;
	}
};

class SavingsAccount: public Account {
public:
    SavingsAccount(){
        balance = 0;
        type = 1;
    }
};
