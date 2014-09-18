class Account{
    double balance;
    bool type;
public:
    Account();
    double getBalance();
    bool getType();
};

class ChequingAccount: public Account{
public:
	ChequingAccount();
};

class SavingsAccount: public Account {
public:
    SavingsAccount();
};
