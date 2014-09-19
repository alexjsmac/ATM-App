#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
    double balance;
    bool type;
public:
    Account();
    double getBalance();
    void setBalance(double newBal);
    bool getType();
    void setType(bool type);
};

class ChequingAccount: public Account{
public:
	ChequingAccount();
};

class SavingsAccount: public Account {
public:
    SavingsAccount();
};

#endif
