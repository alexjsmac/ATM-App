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
