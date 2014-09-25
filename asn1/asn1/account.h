#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
protected:
    double balance;
    bool type;
    int ownerID;
    
public:
    Account(){} //Default constructor
    Account(int);
    double getBalance();
    void setBalance(double newBal);
    bool getType();
    void setType(bool type);
    int getOwnerID();
};

class ChequingAccount: public Account{
public:
	ChequingAccount(int);
};

class SavingsAccount: public Account {
public:
    SavingsAccount(int);
};

#endif
