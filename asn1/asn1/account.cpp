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

void Account::setType(bool newType){
    type = newType;
}

void Account::setBalance(double newBal){
    balance = newBal;
}

ChequingAccount::ChequingAccount(){
		this->setBalance(0);
        this->setType(0);
};

SavingsAccount::SavingsAccount(){
	this->setBalance(0);
	this->setType(1);
};
