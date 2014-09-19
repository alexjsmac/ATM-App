#include <string>

using namespace std;

class User{
    int userID;
    string userName;
    int userType;

    User(){} //Default constructor
public:
    User(int userID, string userName);
    
    int getID();
    string getUserName();
    int getUserType();
};

class Customer: public User {
	ChequingAccount checkingsAcc;
    SavingsAccount savingsAcc;

public:
    Customer(int userID, string userName);
    
    double checkChequingBal();
    double checkSavingsBal();
};

//
//class Manager: public User{
//public:
//    Manager(int, string);
//    int getType();
//    void createUser(int uID, string userName);
//    string dispAccount(int uID);
//};
//
//Manager::Manager(int manID, string manName);
//
//
//class Maintenance: public User{
//public:
//    Maintenance(int, string);
//    void maintenanceMode();
//};
//
//Maintenance::Maintenance(int mainID, string mainName);
