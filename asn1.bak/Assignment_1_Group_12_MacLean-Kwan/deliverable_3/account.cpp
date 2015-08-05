#include <iostream>
#include <string>
#include "account.h"

Account::Account(int ownerID){
	balance = 0;
    this->ownerID = ownerID;
}

double Account::getBalance(){
       return balance;
}

void Account::setBalance(double newBal){
    balance = newBal;
}

bool Account::getType(){
       return type;
}

void Account::setType(bool newType){
    type = newType;
}

int Account::getOwnerID(){
    return ownerID;
}

ChequingAccount::ChequingAccount(int ownerID){
    this->ownerID = ownerID;
    balance = 0;
    type = 0;
};

SavingsAccount::SavingsAccount(int ownerID){
    this->ownerID = ownerID;
    balance = 0;
    type = 1;
};
