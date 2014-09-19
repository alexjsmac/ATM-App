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
    
public:
    User(){} //Default constructor
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
    double checkChequingBal();
    double checkSavingsBal();
};


class Manager: public User{
    std::vector<Customer> customers;
public:
    Manager(int, string);
    int getType();
    void createUser(int, string);
    void deleteUser(int);
    string dispAccount(int);
    Customer findCust(int);
    bool custExists(int);
};


class Maintenance: public User{
public:
    Maintenance(int, string);
    void maintenanceMode();
};

#endif
