#include <iostream>
#include <string>
#include "user.h"

string userName;
int userID;
int userType;

User::User(int userID, string userName, int userType){ //Constructor
    this
}

int getID(){
    return userID;
}

string getUserName(){
    return userName;
}

int getUserType(){
    return userType;
}

//
//class Customer: public User {
//	ChequingAccount checkingsAcc;
//	SavingsAccount savingsAcc;
//public:
//    Customer(int uID, std::string uName){
//        userID = uID;
//        userName = uName;
//        userType = 0;
//    }
//
//    double chAccBalance(){
//        return checkingsAcc.getBalance();
//    }
//
//    double saAccBalance(){
//        return savingsAcc.getBalance();
//    }
//};
//
//class Manager: public User{
//public:
//    Manager (int, string);
//    int getType(){
//        return 1;
//    }
//    void createUser(int uID, string userName){
//        Customer newCust (uID, userName);
//    }
//    string dispAccount(int uID){ //Has to be return not cout
//        Customer foundCust = findCust(int uID);
//        cout<<"Username: ";
//    }
//};
//
//Manager::Manager(int manID, string manName){
//    userID = manID;
//    userName = manName;
//    userType = 1;
//}
//
//
//class Maintenance: public User{
//public:
//    Maintenance (int, string);
//    void maintenanceMode(){
//
//    }
//};
//
//Maintenance::Maintenance(int mainID, string mainName){
//    userID = mainID;
//    userName = mainName;
//    userType = 2;
//}
