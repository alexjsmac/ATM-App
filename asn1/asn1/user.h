#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "account.h"

typedef std::string string;

class User{
protected:
    int userID;
    string userName;
    int userType;
    User(){} //Default constructor
    
public:
    User(int, string);
    int getID();
    string getUserName();
    int getUserType();
};

class Customer: public User {
	ChequingAccount checkingsAcc;
    SavingsAccount savingsAcc;

public:
    Customer(int, string);
    ChequingAccount getChequing();
    SavingsAccount getSavings();
};


class Manager: public User{
    std::vector<Customer> customers;
    
public:
    Manager(int, string);
    int getType();
    void createUser(int, string);
    void deleteUser(int);
    void dispAccount(int);
    void dispAllAccounts();
    Customer findCust(int);
    bool custExists(int);
    std::vector<Customer> custList();
};


class Maintenance: public User{
public:
    Maintenance(int, string);
    void maintenanceMode();
};

#endif
